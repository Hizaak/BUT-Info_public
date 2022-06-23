#include "chaines.h"

void rechercherRemplacer(char carARemplacer, char carRemplacement,
                         string &chaine, unsigned int &nbRempla)
{
    nbRempla = 0;

    // Parcours complet avec remplacement conditionné
    for (int i = 0; i < chaine.size(); i++)
    {
        if (chaine[i] == carARemplacer)
        {
            chaine[i] = carRemplacement;
            nbRempla++;
        }
    }
}

/**
 * @brief la brief
 * 
 * @param carARemplacer 
 * @param carRemplacement 
 * @param chaine 
 * @return unsigned int 
 */
unsigned int rechercherRemplacer(char carARemplacer, char carRemplacement,
                                 string &chaine)
{
    unsigned int nbRempla = 0;

    // Parcours complet avec remplacement conditionné
    for (int i = 0; i < chaine.size(); i++)
    {
        if (chaine[i] == carARemplacer)
        {
            chaine[i] = carRemplacement;
            nbRempla++;
        }
    }
    return nbRempla;
}

bool estSeparateur(char lettre, string separateurs)
{

    // Initialisation de la recherche
    bool estSeparateur = false;
    unsigned int posCourante = 0;

    // Recherche de la 1ere occurrence de lettre dans separateurs
    while (posCourante < separateurs.size() && estSeparateur == false)
    {
        if (separateurs[posCourante] == lettre)
            estSeparateur = true;

        posCourante++;
    }

    return estSeparateur;
}

unsigned int nbMots(string phrase)
{
    unsigned int nbMots = 0; // Le nombre de mots dans phrase
    enum Etat
    {
        dansMot,
        horsMot
    };
    Etat etatCourant; // L'état courant de l'automate
    const string separateurs =
        " ,;.:!"; // La liste des caractères pouvant séparer des mots

    // Déterminer l'état initial de l'automate
    if (estSeparateur(phrase[0], separateurs))
        etatCourant = horsMot;
    else
    {
        etatCourant = dansMot;
        nbMots++;
    }

    // Compter les mots
    for (int i = 1; i < phrase.size(); i++)
    {
        switch (etatCourant)
        {
        case dansMot:
            if (estSeparateur(phrase[i], separateurs)) // on sort d'un mot
                etatCourant = horsMot;
            break;

        case horsMot:
            if (!estSeparateur(phrase[i],
                               separateurs)) // on rencontre un nouveau mot
            {
                etatCourant = dansMot;
                nbMots++;
            }
        }
    }

    return nbMots;
}

string cesar(string phrase, int cle)
{
    string chaineResultat; // La chaîne à retourner

    const string separateurs = " ,;.:'!"; /* La liste des séparateurs.
    Ils ne sont pas soumis aux opérations de chiffrement / déchiffrement */

    char base; /* utilisé dans la formule de chiffrement.
    Valeur égale à 'a' lorsqu'on chiffre / déchiffre une minuscule.
    Valeur égale à 'A' lorsqu'on  chiffre / déchiffre une majuscule. */

    chaineResultat = phrase; /* penser à initialiser chaineResultat avec
    le même nombre de caractères que phrase */

    // Adapter la valeur de la clé en cas de décryptage
    if (cle < 0)
    {
        cle = (cle % 26) + 26;
    }

    // Crypter / décypter les caractères qui doivent l'être
    for (int i = 0; i < phrase.size(); i++)
    {
        if (estSeparateur(phrase[i], separateurs))
        {
            chaineResultat[i] = phrase[i];
        }
        else
        {
            if (phrase[i] >= 'A' &&
                phrase[i] <= 'Z') // on a affaire à une majuscule
            {
                base = 'A';
            }
            else // on a affaire à une minuscule
            {
                base = 'a';
            }
            chaineResultat[i] = (phrase[i] - base + cle) % 26 + base;
        }
    }

    return chaineResultat;
}
