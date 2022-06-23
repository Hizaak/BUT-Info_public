#ifndef MONAMPOULE_H
#define MONAMPOULE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class MonAmpoule : public QWidget
{
    Q_OBJECT

public:
    MonAmpoule(QWidget *parent = nullptr);
    ~MonAmpoule();

public slots:
    void demandeAllumer();     // de this
    void demandeEteindre();    // de this

private:
    QLabel *labelEtat; // éteinte / allumée
    QPushButton *bAllumer;
    QPushButton *bEteindre;

    void afficherParents();
};
#endif // MONAMPOULE_H
