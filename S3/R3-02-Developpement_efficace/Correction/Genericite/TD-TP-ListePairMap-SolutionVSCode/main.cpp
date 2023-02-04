/**
 * @file main.cpp
 * @brief Exemples d'utilisation de pair, de list et de map
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include <iostream>
#include <map>
#include <list>

using namespace std;

/// @fn listeSimple
////////////////////////////////////////////////
void listeSimple() {

	// D�finit une classe ListeS, pour instancier des listes de strings
	typedef list<string> ListeS;

	// Cr�e un objet uneListeS, instance de ListeS
	ListeS uneListeS;

	// Alimente la liste avec "Pantxika", "Yann", "Philippe" et "Patrick"
	uneListeS.push_back (ListeS::value_type ("Pantxika"));
	uneListeS.push_back (ListeS::value_type ("Yann"));
	uneListeS.push_back (ListeS::value_type ("Philippe"));
	uneListeS.push_back (ListeS::value_type ("Patrick"));

	// Cr�e un it�rateur pour parcourir les �l�ments qui composent les listes
             // qui sont instances de la classe ListeS
	ListeS::iterator iterateurDeListeS; 	// Peut contenir d�adresse d�un �l�ment qui
                                            // compose une liste instance de ListeS
	// Initialise l'it�rateur au premier �l�ment de l�instance uneListeS
	iterateurDeListeS = uneListeS.begin();

	// Parcours complet de la liste uneListeS et affiche chaque �l�ment
	while (iterateurDeListeS != uneListeS.end()) {
		cout << *iterateurDeListeS << endl;
		iterateurDeListeS++;		        // Acc�de � l��l�ment suivant qui compose la liste
	}
}


/// @fn listePaires
////////////////////////////////////////////////
void listePaires () {
	// a. D�finit le type PairStringString
	typedef pair <string, string> PairStringString;

	// b. D�finit une classe ListeP, liste de paires de strings
	typedef list <PairStringString> ListeP;

	// Ou bien a. & b. d�un seul coup : d�finition d�une classe ListeP, liste de paires de strings
    /*  typedef list <pair <string, string> > ListeP;  */

	// Cr�e un objet uneListeP, instance de la ListeP
	ListeP uneListeP;

	// Alimente la liste avec des valeurs
	uneListeP.push_back (ListeP::value_type ("Pantxika ", "06.01.01.01.01"));
	uneListeP.push_back (ListeP::value_type ("Yann", "06.02.02.02.02"));
	uneListeP.push_back (ListeP::value_type ("Philippe", "06.03.03.03.03"));
	uneListeP.push_back (ListeP::value_type ("Patrick", "06.04.04.04.04"));

	// Cr�e un it�rateur pour parcourir les �l�ments qui composent les instances de ListeP
	ListeP::iterator iterateurDeListeP;

	// Initialise l'iterateur au premier element de uneListeP, instance de ListeP
	iterateurDeListeP = uneListeP.begin();

	// Parcours complet de la liste uneListeP et affiche les composants de chacun de ses elements
	while (iterateurDeListeP != uneListeP.end()) {
		cout << iterateurDeListeP->first << " - " << iterateurDeListeP->second << endl;
		iterateurDeListeP++;                // Acc�de � l'�l�ment suivant
	}
}


/// @fn leMap
////////////////////////////////////////////////
void leMap ()
{
/// DELCARATIONS

    // D�finit une classe Annuaire, une map de string avec string en clef
    typedef map <string, string> Annuaire;

    // Cr�e un objet unAnnuaire, instance de Annuaire
    Annuaire unAnnuaire;

    // Etablit le type IterateurAnnuaire
    typedef Annuaire::iterator IterateurAnnuaire;

    // Cr�e resultatInsert une paire de valeurs qui r�cup�re le r�sultat d�une insertion
    pair <IterateurAnnuaire, bool> resultatInsert;  // On aurait pu passer par un typedef
    // La seconde valeur vaut true si l'insertion est frustueuse et false sinon
    // En cas d'insertion fructueuse, la premi�re valeur contient l'adresse de l'�l�ment ins�r�
    // En cas d'insertion infructueuse, la premi�re valeur contient l'adresse de l'�l�ment ayant
    // la m�me clef

/// TRAITEMENTS

    // Alimente l'annuaire avec "Pantxika", "06.01.01.01.01" et teste le r�sultat
    resultatInsert = unAnnuaire.insert(Annuaire::value_type("Pantxika", "06.01.01.01.01"));
    if (resultatInsert.second == true) 	     	// Si insertion fructueuse
        cout << "Insertion " << resultatInsert.first -> first
             << " BIEN realisee" << endl;
    else                                    	// Sinon
        cout << "Insertion MAL realisee" << endl;

    // R�alimente l'annuaire avec "Pantxika", "06.01.01.01.01" et teste le r�sultat
    resultatInsert=unAnnuaire.insert(Annuaire::value_type("Pantxika", "06.01.01.01.01"));
    if (resultatInsert.second == true)      	// Si insertion infructueuse
        cout << "Insertion " << resultatInsert.first -> first
             << " BIEN realisee" << endl;
    else                                    	// Sinon
        cout << "Insertion MAL realisee" << endl;

    // Alimente unAnnuaire de trois autres tuples
    unAnnuaire.insert (Annuaire::value_type ("Yann", "06.02.02.02.02"));
    unAnnuaire.insert (Annuaire::value_type ("Philippe", "06.03.03.03.03"));
    unAnnuaire.insert (Annuaire::value_type ("Patrick", "06.04.04.04.04"));

	// Cr�e un iterateur pour parcourir les objets de Annuaire
	IterateurAnnuaire    unInterateur;

	// Initialise l'iterateur au premier �l�ment de unAnnuaire
	unInterateur = unAnnuaire.begin ();

    // Parcours complet de la liste et affiche le second composant de chaque �l�ment
	while (unInterateur != unAnnuaire.end()) {
		cout << unInterateur -> second << endl;
		unInterateur ++;         // Acc�s � l��l�ment suivant
	}

	// La m�thode find() retourne un it�rateur sur la paire de clefRecherchee ou bien sur end()
	string clefRecherchee = "Philippe";
    unInterateur = unAnnuaire.find (clefRecherchee);

	// Affiche le num�ro de t�l�phone ou bien : Philippe - clef inconnue
	if (unInterateur != unAnnuaire.end())
            cout << clefRecherchee << "  - telephone : " << unInterateur->second << endl;
    else 	cout << clefRecherchee  << " clef inconnue" << endl;
}


/// @fn main()
////////////////////////////////////////////////
main ()
{
    cout << "### LISTE SIMPLE\n";
    listeSimple ();

    cout << "\n\n### LISTE DE PAIRES\n";
    listePaires ();

    cout << "\n\n### MAP\n";
    leMap ();
}

