#include "principale.h"
#include "ui_principale.h"

Principale::Principale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principale)
{
    ui->setupUi(this);
}

Principale::~Principale()
{
    delete ui;
}

