#include "monampoule.h"
#include "ui_monampoule.h"

monAmpoule::monAmpoule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::monAmpoule)
{
    ui->setupUi(this);

    // paramétrage initiaux des widgets
    ui->labelEtat->setText("éteint !");
    ui->bAllumer->setEnabled(true);
    ui->bEteindre->setEnabled(false);

    // connexions
    connect(ui->bAllumer, SIGNAL(clicked()), this, SLOT(demandeAllumer()));
    connect(ui->bEteindre, SIGNAL(clicked()), this, SLOT(demandeEteindre()));
}

monAmpoule::~monAmpoule()
{
    delete ui;
}

void monAmpoule::demandeAllumer()
{
    ui->labelEtat->setText("allumé !");
    ui->bAllumer->setEnabled(false);
    ui->bEteindre->setEnabled(true);

}

void monAmpoule::demandeEteindre()
{
     ui->labelEtat->setText("éteint !");
     ui->bAllumer->setEnabled(true);
     ui->bEteindre->setEnabled(false);
}

