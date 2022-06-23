#ifndef AMPOULEVUE_H
#define AMPOULEVUE_H

#include <QWidget>
#include "modele.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AmpouleVue; }
QT_END_NAMESPACE

class AmpouleVue : public QWidget
{
    Q_OBJECT

public:
    AmpouleVue(QWidget *parent = nullptr);
    ~AmpouleVue();
public:
    // pour créer une connexion avec la présentation
    void nvlleConnexion(QObject *c);
    void supprConnexion(QObject *c);
    // ordres reçus par la présentation
    void majInterface (Modele::UnEtat e);

private:
    Ui::AmpouleVue *ui;
};
#endif // AMPOULEVUE_H
