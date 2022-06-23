#include "chaines.h"

/**
 * @brief pouetpouet
 * 
 * @return int 
 */
int main(void)
{
  // Variables
  string chaineEnclair = "Bonjour"; // La chaîne à encoder selon le cryptage de César
  string chaineEncodee;             // La version encodée de chaineEnclair
  const int CLE = 2; // La valeur de la clé de cryptage

  // Test cryptage
  chaineEncodee = cesar(chaineEnclair, CLE);
  cout << "Cryptage de " << chaineEnclair << " :" << endl;
  cout << chaineEncodee << endl << endl;

  // Test décryptage
  chaineEnclair = cesar(chaineEncodee, -CLE);
  cout << "Décryptage de " << chaineEncodee <<endl;
  cout << chaineEnclair << endl;

  return 0;
}