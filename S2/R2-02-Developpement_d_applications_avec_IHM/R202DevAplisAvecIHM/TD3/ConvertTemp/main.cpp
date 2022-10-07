#include "convertisseurtemperature.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QObject>
#include <Qt>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConvertisseurTemperature w;


    w.show();
    return a.exec();
}
