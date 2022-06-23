#ifndef CONVETISSEURTEMP_H
#define CONVETISSEURTEMP_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QObject>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <Qt>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ConvetisseurTemp; }
QT_END_NAMESPACE

class ConvetisseurTemp : public QMainWindow
{
    Q_OBJECT

public:
    ConvetisseurTemp(QWidget *parent = nullptr);
    ~ConvetisseurTemp();

public slots:
    void razero();
    void convertir();
    void versSEL(int);
    void versSlider();
private:
    Ui::ConvetisseurTemp *ui;
};
#endif // CONVETISSEURTEMP_H
