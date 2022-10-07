#include "ampoulevue.h"
#include "ui_ampoulevue.h"

AmpouleVue::AmpouleVue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AmpouleVue)
{
    ui->setupUi(this);
}

AmpouleVue::~AmpouleVue()
{
    delete ui;
}

void AmpouleVue::nvlleConnexion(QObject *c)
{
    //pour se connecter avec la presentation
    QObject::connect(ui->bAllumer, SIGNAL(clicked()), c, SLOT(demandeAllumer()));
    QObject::connect(ui->bEteindre, SIGNAL(clicked()), c, SLOT(demandeEteindre()));
}

void AmpouleVue::supprConnexion(QObject *c)
{
    //pour se déconnecter de c
    QObject::disconnect(ui->bAllumer, SIGNAL(clicked()), c, SLOT(demandeAllumer()));
    QObject::disconnect(ui->bEteindre, SIGNAL(clicked()), c, SLOT(demandeEteindre()));
}

void AmpouleVue::majInterface(Modele::UnEtat e)
{
    switch (e) {
        case Modele::allume :
            ui->labelEtat->setText("allumé !");
            ui->bAllumer->setEnabled(false);
            ui->bEteindre->setEnabled(true);
            break;
        case Modele::eteint :
            ui->labelEtat->setText("éteint !");
            ui->bAllumer->setEnabled(true);
            ui->bEteindre->setEnabled(false);
            break;
        default: break;
    }
}

