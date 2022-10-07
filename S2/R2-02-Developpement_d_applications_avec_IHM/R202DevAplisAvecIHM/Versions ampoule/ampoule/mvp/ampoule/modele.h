#ifndef MODELE_H
#define MODELE_H

#include <QObject>

class Modele : public QObject
{
    Q_OBJECT
public:
    enum UnEtat {eteint, allume};
    explicit Modele(UnEtat e=eteint, QObject *parent = nullptr);
    void allumer();
    void eteindre();
    UnEtat getEtat();
private:
    UnEtat _etat;
};

#endif // MODELE_H
