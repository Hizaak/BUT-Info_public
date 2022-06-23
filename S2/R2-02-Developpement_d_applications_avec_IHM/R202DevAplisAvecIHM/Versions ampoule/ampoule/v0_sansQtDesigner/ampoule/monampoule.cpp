#include "monampoule.h"
#include <QLayout>
#include <QDebug>
#include <QLabel>

MonAmpoule::MonAmpoule(QWidget *parent)
    : QWidget(parent)
{
    // création des objets
    labelEtat = new QLabel(tr("éteinte !"));
    bAllumer = new QPushButton(tr("Allumer"));
    bEteindre = new QPushButton(tr("Eteindre"));

    // Paramétrage des widgets
    this->setWindowTitle(tr("Ampoule"));
    bEteindre->setEnabled(false);

    // Uniquement pour la visualisation de la mise au point graphique
    // labelEtat->setAlignment(Qt::AlignHCenter);       // alignement par défaut : AlignLeft
    labelEtat->setFrameStyle(QFrame::Shape::Box);    // cadre autour du widget

    // Création des layout
    QVBoxLayout *vPrincipalLayout = new QVBoxLayout;
    QHBoxLayout *hBoutonsLayout = new QHBoxLayout;

    // Peuplement des layouts
    hBoutonsLayout->addWidget(bAllumer);
    hBoutonsLayout->addWidget(bEteindre);
    vPrincipalLayout->addWidget(labelEtat);
    vPrincipalLayout->addLayout(hBoutonsLayout);

    // Associer layout principal à Widget
    this->setLayout(vPrincipalLayout);

    // connexions
    connect(bAllumer, SIGNAL(clicked()), this, SLOT(demandeAllumer()));
    connect(bEteindre, SIGNAL(clicked()), this, SLOT(demandeEteindre()));
}

MonAmpoule::~MonAmpoule()
{
}

void MonAmpoule::demandeAllumer()
{
    labelEtat->setText("allumé !");
    bAllumer->setEnabled(false);
    bEteindre->setEnabled(true);

}

void MonAmpoule::demandeEteindre()
{
     labelEtat->setText("éteint !");
     bAllumer->setEnabled(true);
     bEteindre->setEnabled(false);
}










void MonAmpoule::afficherParents()
{
    qDebug() << labelEtat->parent() << Qt::endl;
    qDebug() << bAllumer->parent() << Qt::endl;
    qDebug() << bEteindre->parent() << Qt::endl;
}


/*
 *  QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelEtat->sizePolicy().hasHeightForWidth());
    labelEtat->setSizePolicy(sizePolicy);
    labelEtat->setAlignment(Qt::AlignCenter);

 * */

/*
 *
    QLabel monLineEdit1("1", this);                 // objet
    QLabel *monLineEdit2 = new QLabel("2", this);   // pteur sur objet

    vPrincipalLayout->addWidget(&monLineEdit1); // NON car la variable est perdue après
                                                // exécution du constructeur
    vPrincipalLayout->addWidget(monLineEdit2);

    qDebug() << monLineEdit1.parent() << Qt::endl;
    qDebug() << monLineEdit2->parent() << Qt::endl;
    qDebug() << monLineEdit1.text() << Qt::endl;
    qDebug() << monLineEdit2->text() << Qt::endl;

 * */
