#ifndef MACLASSE_H
#define MACLASSE_H

#include <QObject>

class MaClasse : public QObject
{
    Q_OBJECT
public:
    explicit MaClasse(QObject *parent = nullptr);
    void emettre();
    int getNumero();
public slots:
    void recevoir(int);
signals:
    void estEmis(int); // déclenché par méthode envoyer()
    void estParti(); // pour quitter l'aplication
private:
    int _numero; // rang de creation
};

#endif // MACLASSE_H
