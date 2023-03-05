#include "algorithmdialog.h"
#include "ui_algorithmdialog.h"

AlgorithmDialog::AlgorithmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlgorithmDialog)
{
    ui->setupUi(this);
}

AlgorithmDialog::~AlgorithmDialog()
{
    delete ui;
}
