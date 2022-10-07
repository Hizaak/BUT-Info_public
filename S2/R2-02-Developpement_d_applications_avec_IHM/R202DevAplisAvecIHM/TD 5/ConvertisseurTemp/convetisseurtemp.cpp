#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QObject>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <Qt>
#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QMessageBox>
#include "convetisseurtemp.h"
#include "ui_convetisseurtemp.h"
#include <iostream>
using namespace std;

ConvetisseurTemp::ConvetisseurTemp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConvetisseurTemp)
{
    ui->setupUi(this);
    QObject::connect(ui->PBQuitter,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->PBConvertir,SIGNAL(clicked()),this,SLOT(convertir()));
    QObject::connect(ui->PBRazeRo,SIGNAL(clicked()),this,SLOT(razero()));
    QObject::connect(ui->STemperature,SIGNAL(valueChanged(int)),this, SLOT(versSEL(int)));
    QObject::connect(ui->SELinput,SIGNAL(textChanged(QString)),this,SLOT(versSlider()));
}

ConvetisseurTemp::~ConvetisseurTemp()
{
    delete ui;
}

void ConvetisseurTemp::convertir(){
    bool estCorrecte;
    ui->SELinput->text().split(" ")[0].toFloat(&estCorrecte);
    if(true){
        float valeur;
        valeur = ui->SELinput->text().split(" ")[0].toFloat();
        valeur = valeur*(1.8)+32.0;
        QString ValeurAffichage = QString::number(valeur);
        ui->LResultat->setText(ValeurAffichage);
    }
    else{
        razero();
    }
}


void ConvetisseurTemp::razero(){
    ui->STemperature->setValue(0);
    ui->LResultat->setText("--.--");
    //ui->SELinput->setText("");
}

void ConvetisseurTemp::versSEL(int valeur){
    ui->SELinput->setText(QString::number(valeur));
    this->convertir();
}

void ConvetisseurTemp::versSlider(){
    ui->STemperature->setValue((ui->SELinput->text().toFloat()));
    this->convertir();
}


