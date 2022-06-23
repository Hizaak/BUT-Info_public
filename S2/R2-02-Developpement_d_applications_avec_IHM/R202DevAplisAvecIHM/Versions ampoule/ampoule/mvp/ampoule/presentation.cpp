#include "presentation.h"
#include "ampoulevue.h"
#include <QDebug>

Presentation::Presentation(Modele *m, QObject *parent)
    : QObject{parent}, _leModele(m)
{
    _leModele->eteindre();
}

Modele *Presentation::getModele()
{
    return _leModele;
}

AmpouleVue *Presentation::getVue()
{
    return _laVue;
}

void Presentation::setModele(Modele *m)
{
    _leModele = m;
}

void Presentation::setVue(AmpouleVue *v)
{
    _laVue = v;
}

void Presentation::demandeAllumer()
{
    _leModele->allumer();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demandeEteindre()
{
    _leModele->eteindre();
    _laVue->majInterface(_leModele->getEtat());
}
