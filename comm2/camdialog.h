#ifndef CAMDIALOG_H
#define CAMDIALOG_H

#include <QDialog>

namespace Ui {
class CamDialog;
}

class CamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CamDialog(QWidget *parent = nullptr);
    ~CamDialog();

private:
    Ui::CamDialog *ui;
};

#endif // CAMDIALOG_H
