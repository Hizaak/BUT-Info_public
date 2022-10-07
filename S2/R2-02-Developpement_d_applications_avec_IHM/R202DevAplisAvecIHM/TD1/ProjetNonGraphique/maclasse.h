#ifndef MACLASSE_H
#define MACLASSE_H

#include <QObject>

class MaClasse : public QObject
{
    Q_OBJECT
private:
    int _numero;
public:
    explicit MaClasse(int num, QObject *parent = nullptr);

    // Constructeurs
    MaClasse();

    // Méthodes
    void emettre(int);
    void recevoir(int);
signals:
    void estEmis(int);
};

#endif // MACLASSE_H
