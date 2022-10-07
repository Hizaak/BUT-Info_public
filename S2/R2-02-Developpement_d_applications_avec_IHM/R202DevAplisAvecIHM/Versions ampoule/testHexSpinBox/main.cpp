#include <QApplication>
#include "hexspinbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexSpinBox w;
    w.show();
    return a.exec();
}
