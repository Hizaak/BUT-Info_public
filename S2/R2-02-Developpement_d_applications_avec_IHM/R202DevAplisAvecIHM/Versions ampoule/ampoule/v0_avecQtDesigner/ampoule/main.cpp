#include "monampoule.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    monAmpoule w;
    w.show();
    return a.exec();
}
