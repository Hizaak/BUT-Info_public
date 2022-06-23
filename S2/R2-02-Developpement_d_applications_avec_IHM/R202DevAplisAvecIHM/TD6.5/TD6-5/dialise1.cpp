#include "dialise1.h"
#include "ui_dialise1.h"

dialise1::dialise1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialise1)
{
    ui->setupUi(this);
}

dialise1::~dialise1
{
    delete ui;
}
