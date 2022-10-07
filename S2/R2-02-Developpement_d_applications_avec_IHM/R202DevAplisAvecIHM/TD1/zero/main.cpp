#include "principale.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principale w;
    w.show();
    return a.exec();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
