#include "monampoule.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MonAmpoule w;
    w.show();
    return a.exec();
}
