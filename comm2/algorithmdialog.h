#ifndef ALGORITHMDIALOG_H
#define ALGORITHMDIALOG_H

#include <QDialog>

namespace Ui {
class AlgorithmDialog;
}

class AlgorithmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlgorithmDialog(QWidget *parent = nullptr);
    ~AlgorithmDialog();

private:
    Ui::AlgorithmDialog *ui;
};

#endif // ALGORITHMDIALOG_H
