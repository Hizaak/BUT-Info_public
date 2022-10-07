#ifndef MACLASSE_H
#define MACLASSE_H

#include <QObject>

class MaClasse : public QObject
{
    Q_OBJECT
public:
    explicit MaClasse(QObject *parent = nullptr);

signals:

};

#endif // MACLASSE_H
