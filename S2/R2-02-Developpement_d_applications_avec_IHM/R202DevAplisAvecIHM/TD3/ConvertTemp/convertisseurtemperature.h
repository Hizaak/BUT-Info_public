#ifndef CONVERTISSEURTEMPERATURE_H
#define CONVERTISSEURTEMPERATURE_H
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

class ConvertisseurTemperature : public QMainWindow
{
    Q_OBJECT

public:
    ConvertisseurTemperature(QWidget *parent = nullptr);
    ~ConvertisseurTemperature();
private:
    // Label Titre
    QLabel* LTitre;
    QFont police;
    // Label Resultat
    QLabel* Lresultat;
    QFont Fresultat;
    // Label Celsius
    QLabel* Lcelsius;
    // Label Fahrenheit
    QLabel* Lfahrenheit;
    QFont Ffahrenheint;
    // Single Entry Line
    QLineEdit* SELinput;
    // Effacer
    QPushButton* PBeffacer;
    // Quitter
    QPushButton* PBquitter;
    // Convertir
    QPushButton* PBconvertir;

    float _resultat;
    int _input;
    float _degres;
public slots:
    void effacer();
    void convertir();

};
#endif // CONVERTISSEURTEMPERATURE_H
