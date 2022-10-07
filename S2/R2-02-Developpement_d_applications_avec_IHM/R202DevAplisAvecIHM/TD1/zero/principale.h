#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principale; }
QT_END_NAMESPACE

class Principale : public QMainWindow
{
    Q_OBJECT
private:
    Ui::Principale *ui;
    int _numero;
public slots:
    Principale(QWidget *parent = nullptr);
    ~Principale();
    void emettre();
    void recevoir(int); // slot : corps à définir dans .cpp
    void quitter();
signals:
    void estEmis(int); // signal : pas de corps à définir dans .cpp
};
#endif // PRINCIPALE_H
