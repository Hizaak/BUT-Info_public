#include "convertisseurtemperature.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QObject>

ConvertisseurTemperature::ConvertisseurTemperature(QWidget *parent)
    : QMainWindow(parent)
{
    // Paramètres de la fenêtre
    this->setWindowTitle("Convertisseur de températures");
    this->setMinimumSize(800,500);

    // Label LTitre
    LTitre = new QLabel("Arial font",this);
    LTitre->setText("Convertisseur de températures");
    police = LTitre->font();
    police.setPointSize(20);
    police.setBold(true);
    LTitre->setFont(police);
    LTitre->setGeometry(16,20,430,30);

    // Label Lresultat
    Lresultat = new QLabel("Arial font",this);
    Lresultat->setText("--.--");
    Fresultat = LTitre->font();
    Fresultat.setPointSize(11);
    Fresultat.setBold(true);
    Lresultat->setFont(Fresultat);
    Lresultat->setGeometry(256,93,63,20);

    // Label Celsius
    Lcelsius = new QLabel(this);
    Lcelsius->setText("Degrés Celsius");
    Lcelsius->setGeometry(116,70,101,20);

    // Label Fahrenheit
    Lfahrenheit = new QLabel("Arial font",this);
    Lfahrenheit->setText("Degrés Fahrenheit");
    Ffahrenheint = Lfahrenheit->font();
    Ffahrenheint.setPointSize(11);
    Lfahrenheit->setFont(Ffahrenheint);
    Lfahrenheit->setGeometry(256,70,125,20);

    // Single Entry Line
    SELinput = new QLineEdit(this);
    SELinput->setGeometry(116,92,91,26);

    // Effacer
    PBeffacer = new QPushButton(this);
    PBeffacer->setText("Effacer");
    PBeffacer->setGeometry(16,160,93,29);
    //QObject::connect(PBquitter,SIGNAL(clicked()),this,SLOT(effacer()));


    // Quitter
    PBquitter = new QPushButton(this);
    PBquitter->setText("Quitter");
    PBquitter->setGeometry(336,160,93,29);
    QObject::connect(PBquitter,SIGNAL(clicked()),this,SLOT(close()));

    // Convertir
    PBconvertir = new QPushButton(this);
    PBconvertir->setText("Convertir");
    PBconvertir->setGeometry(116,160,93,29);
    QObject::connect(PBquitter,SIGNAL(clicked()),this,SLOT(convertir()));

}

ConvertisseurTemperature::~ConvertisseurTemperature()
{
}

void ConvertisseurTemperature::convertir(){
    *this->SELinput->text()
    valeur=valeur*(9/4)+32;
    QString ValeurAffichage = QString::number(valeur);
    Lresultat->setText(ValeurAffichage);
}

