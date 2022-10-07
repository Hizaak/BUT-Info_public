#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
class AmpouleVue;
class Presentation : public QObject
{
    Q_OBJECT
public:
    explicit Presentation(Modele *m, QObject *parent = nullptr);
public:
    Modele* getModele();
    AmpouleVue* getVue();
    void setModele(Modele *m);
    void setVue(AmpouleVue *v);
signals:
public slots:   // déclenchés par la vue
    void demandeAllumer();
    void demandeEteindre();
private:
    Modele *_leModele;
    AmpouleVue *_laVue;
};

#endif // PRESENTATION_H
