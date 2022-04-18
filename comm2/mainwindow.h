#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gaussdialog.h"
#include "camdialog.h"
#include "algorithmdialog.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  //     void initSerialPort();//初始化串口函数

private slots:
  void aboutme();
  void on_openConnButton_clicked();
  void readData();
  //    void on_comboBoxSeriNum_currentIndexChanged(const QString &arg1);
  void serialRead();
  void readCurData();
  void sendString(QString qstr);
  void on_sendDataButton_clicked();

  void on_closeConnButton_clicked();

  void on_sendCurButton_clicked();

  void on_recCurButton_clicked();

  void on_clearDataButton_clicked();



  void on_actionAbout_triggered();

  void on_actionGauss_triggered();

  void on_actionCam_triggered();

  void on_actionIndex_triggered();

  void on_actionenv_triggered();

private:
  Ui::MainWindow *ui;
  QSerialPort *serial; //串口实例
  GaussDialog *gaussdialog;
  CamDialog *camdialog;
  AlgorithmDialog *algorithmdialog;
};

#endif // MAINWINDOW_H
