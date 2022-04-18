#include "camdialog.h"
#include "ui_camdialog.h"

CamDialog::CamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamDialog)
{
    ui->setupUi(this);
}

CamDialog::~CamDialog()
{
    delete ui;
}
