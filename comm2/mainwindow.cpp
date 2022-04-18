#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QMessageBox>

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QString>

using namespace std;
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(aboutme()));

    serial = new QSerialPort;

    QString description;
    QString manufacturer;
    QString serialNumber;

    //获取可以用的串口
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();

    //输出当前系统可以使用的串口个数
    qDebug() << "total ports" << serialPortInfos.count();
    //将所有可以使用的串口设备添加到ComboBox中
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos)
    {
        QStringList list;
        description = serialPortInfo.description();
        manufacturer = serialPortInfo.manufacturer();
        serialNumber = serialPortInfo.serialNumber();

        list << serialPortInfo.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << serialPortInfo.systemLocation()
             << (serialPortInfo.vendorIdentifier() ? QString::number(serialPortInfo.vendorIdentifier(), 16) : blankString)
             << (serialPortInfo.productIdentifier() ? QString::number(serialPortInfo.productIdentifier(), 16) : blankString);
        //               qSort(list.begin(), list.end());
        ui->comboBoxSeriNum->addItem(list.first(), list);
    }

    //        ui->comboBoxSeriNum->addItem(tr("custom"));

    //设置波特率
    ui->comboBoxBaudRate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->comboBoxBaudRate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->comboBoxBaudRate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->comboBoxBaudRate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    //        ui->comboBoxBaudRate->addItem(tr("Custom"));

    //设置数据位
    ui->comboBoxDataBit->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->comboBoxDataBit->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->comboBoxDataBit->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->comboBoxDataBit->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->comboBoxDataBit->setCurrentIndex(3);

    //设置奇偶校验位
    ui->comboBox_parity->addItem(tr("None"), QSerialPort::NoParity);
    ui->comboBox_parity->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->comboBox_parity->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->comboBox_parity->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->comboBox_parity->addItem(tr("Space"), QSerialPort::SpaceParity);

    //设置停止位
    ui->comboBoxStopBit->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    ui->comboBoxStopBit->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    //添加流控
    ui->comboBox_flowBit->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->comboBox_flowBit->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->comboBox_flowBit->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

    //禁用发送按钮
    ui->sendDataButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aboutme()
{
    QMessageBox msg;
    msg.setText("由杨正谦制作!");
    msg.exec();
    qDebug() << "yzq" << endl;
}
void MainWindow::on_sendDataButton_clicked()
{
    //   QByteArray arr = "abcd";
    //   serial.write(arr);
    if (serial->isOpen())
    {
        QByteArray sendQArray;
        QString sendOrder = ui->textEditSendData->toPlainText();
        QString sendStr = QString("%1\r").arg(sendOrder);

        //    cout << data << endl;
        //    sendQArray.append(sendStr);
        cout << sendStr.toStdString() << endl;
        sendString(sendStr);
        //    serial.write(buf_OUT, 5);
    }
    else
    {
        cout << "not open" << endl;
    }
}
void MainWindow::serialRead()
{
    QByteArray qa = serial->readAll();
    //  if(qa.at(0)=='a')
    ui->textBrowserReceive->append(qa);
    // str.sprintf("%02x ",(int)qa[i]);//十六进制显示
    QMessageBox::warning(this, tr("提示信息"), tr("串口接收成功"));
}

void MainWindow::on_openConnButton_clicked()
{
    //    qDebug() << ui->openConnButton->text();

    if (ui->openConnButton->text() == tr("打开串口"))
    {

        cout << "set port" << endl;
        //设置串口名字

        serial->open(QIODevice::ReadWrite); //读写打开
        serial->setPortName(ui->comboBoxSeriNum->currentText());

        //设置波特率
        serial->setBaudRate(ui->comboBoxBaudRate->currentText().toInt());

        //设置数据位
        serial->setDataBits(QSerialPort::Data8);

        //设置奇偶校验位
        serial->setParity(QSerialPort::NoParity);

        //设置停止位
        serial->setStopBits(QSerialPort::OneStop);

        //设置流控
        serial->setFlowControl(QSerialPort::NoFlowControl);

        //打开串口
        serial->open(QIODevice::ReadWrite);

        cout << "port opened\n";
        ui->comboBoxBaudRate->setEnabled(false);
        ui->comboBoxDataBit->setEnabled(false);
        ui->comboBox_flowBit->setEnabled(false);
        ui->comboBox_parity->setEnabled(false);
        ui->comboBoxSeriNum->setEnabled(false);
        ui->comboBoxStopBit->setEnabled(false);

        ui->sendDataButton->setEnabled(true);

        //信号与槽函数关联
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    }
}

void MainWindow::on_closeConnButton_clicked()
{
    cout << "port closed";
    //关闭串口
    //serial->clear();
    serial->close();
    //serial->deleteLater();

    //恢复设置功能
    ui->comboBoxBaudRate->setEnabled(true);
    ui->comboBoxDataBit->setEnabled(true);
    ui->comboBox_flowBit->setEnabled(true);
    ui->comboBox_parity->setEnabled(true);
    ui->comboBoxSeriNum->setEnabled(true);
    ui->comboBoxStopBit->setEnabled(true);

    ui->sendDataButton->setEnabled(false);
}
void MainWindow::sendString(QString qstr)
{
    int count;
    count = qstr.length();
    QByteArray array;

    array.resize(count);
    for (int i = 0; i < count; ++i)
    {
        QChar m = qstr.at(i);
        array[i] = m.toLatin1();
    }
    serial->write(array);
}
//设置电流值
void MainWindow::on_sendCurButton_clicked()
{
    QString str = ui->textEditSendCurData->toPlainText();

    if (str.isNull() || str.isEmpty())
    {
        QMessageBox msg;
        msg.setText("请输入电流值!");msg.exec();
        ui->textEditSendCurData->setFocus();
    }
    else
    {

        QString status = QString("CUR %1\r")
                             .arg(str);
        cout << status.toStdString() << endl;
        sendString(status);
    }
}

void MainWindow::on_recCurButton_clicked()
{
    QString reccur = QString("CUR?\r");
    int count;
    count = reccur.length();
    QByteArray array;

    array.resize(count);
    for (int i = 0; i < count; ++i)
    {
        QChar m = reccur.at(i);
        array[i] = m.toLatin1();
    }
    serial->write(array);
    QString rec = tr(serial->readAll());
    cout << rec.toStdString() << endl;

    //todo
}
void MainWindow::readCurData()
{

    QByteArray buf;

    qDebug() << "this is funced" << endl;
}
void MainWindow::readData()
{
    QByteArray buf;

    buf = serial->readAll();
    if (!buf.isEmpty())
    {
        QString str = ui->textBrowserReceive->toPlainText();

        str += tr(buf);
        ui->textBrowserReceive->clear();
        ui->textBrowserReceive->append(str);
        qDebug() << "readData: " + str << endl;
    }
}

void MainWindow::on_clearDataButton_clicked()
{
    ui->textBrowserReceive->clear();
}

void MainWindow::on_actionAbout_triggered()
{
}

void MainWindow::on_actionGauss_triggered()
{
    //新建一个窗口对象，其中的this指定了新的窗口的父对象是MainWindow，在销毁Mainwindow时也会销毁子对象，即该窗口对象
        gaussdialog = new GaussDialog(this);
        //Modal属性决定了show()应该将弹出的dialog设置为模态还是非模态
        //默认情况下该属性为false并且show（）弹出的窗口是非模态的
        //把这个属性设置为true就详单与设置QWidget::windowModality为Qt::ApplicationModal
        //执行exec（）忽略这个Modal这个属性，并且把弹出的dialog设置为模态的
        gaussdialog->setModal(false);    //此处ture为模态，false为非模态
        gaussdialog->show();
}

void MainWindow::on_actionCam_triggered()
{
    camdialog=new CamDialog(this);
    camdialog->setModal(false);
    camdialog->show();
}

void MainWindow::on_actionIndex_triggered()
{
    QMessageBox msgindex;
    msgindex.setText("没有索引!!!");
    msgindex.exec();
}

void MainWindow::on_actionenv_triggered()
{
    algorithmdialog =new AlgorithmDialog(this);
    algorithmdialog->setModal(false);
    algorithmdialog->show();
}
