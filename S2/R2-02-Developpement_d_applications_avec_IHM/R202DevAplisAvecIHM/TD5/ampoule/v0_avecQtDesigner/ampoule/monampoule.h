#ifndef MONAMPOULE_H
#define MONAMPOULE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class monAmpoule; }
QT_END_NAMESPACE

class monAmpoule : public QWidget
{
    Q_OBJECT

public:
    monAmpoule(QWidget *parent = nullptr);
    ~monAmpoule();
public slots:
    void demandeAllumer();     // de this
    void demandeEteindre();    // de this

private:
    Ui::monAmpoule *ui;
};
#endif // MONAMPOULE_H
