#include "voiture.h"
#include "individu.h"
#include <iostream>
using namespace std;

int main(void){
    Individu individu("Dupont", "Jean");
    Voiture voiture("Peugeot", "AB-123-CD", individu);
    cout << voiture.to_string() << endl;
    return 0;

    
}
