#include "maclasse.h"
#include <iostream>
using namespace std;

MaClasse::MaClasse(int num, QObject *parent) : QObject(parent), _numero(num)
{
    cout << "creation de " << _numero ;
}
