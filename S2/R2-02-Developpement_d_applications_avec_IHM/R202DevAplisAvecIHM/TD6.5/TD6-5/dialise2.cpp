#include "dialise2.h"
#include "ui_dialise2.h"

dialise2::dialise2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialise2)
{
    ui->setupUi(this);
}

dialise2::~dialise2()
{
    delete ui;
}
