/*
 Programme : Jeu : Deviner un nombre
 But :  Le Programme génere un nombre aléatoire et oriente le joueur en fonction de sa saisie
 Date de dernière modification : 29 septembre 2021
 Auteur : Nicolas Dargazanli & Alexandre Maurice
 Remarques : Ajout d'extension
*/
#include <iostream>
#include "game-tools.h"
using namespace std;

int main(void)
{
    //Affichage des règles
    cout << "D E V I N E R   U N   N O M B R E " << endl; //Affichage de l'intitulé
    cout << "Le joueur cherche une valeur dans un intervalle connu, et en un nombre de tentative connu.\n" << endl; //Explication des règles

    //VARIABLES
    int nbTentatives;                  //Le nombre de tentatives (saisies par l'utilisateur)
    int tentative;                     //Le nombre de tentative au fil du jeu (variable incrémentée automatiquement)
    int nbAChercher;                   //Le nombre que le joueur doit chercher (généré aléatoirement)#include "game-tools.h"
    int borneMin;                      //Borne minimale de l'intervalle (saisie par l'utilisateur)
    int borneMax;                      //Borne maximale de l'intervalle (saisie par l'utilisateur)
    int nbSaisi;                       //Stocke le nombre proposé par le joueur pendant la partie (saisies par l'utilisateur)

    //Initialisation de la partie
 
  do{ //On attend du joueur un nombre superieur ou égal à 1
        cout<<"Combien de tentatives voulez-vous (le minimum est 1) ? ";
        cin >> nbTentatives; //Clavier >> saisirNombreTentative >> nbTentatives
        if(nbTentatives>=1){
            break;
        }
        cout <<"Erreur : entrez un nombre de tentatives correct !"<<endl; //Affichage d'un message d'erreur si le nombre de tentatives est incorrect
        cout <<endl; //Saut de ligne (mise en page)
    }while (nbTentatives<1);
    
    cout <<endl; //Saut de ligne (mise en page)
    //Saisie des bornes 
    cout <<"Entrez la borne minimale: ";
    cin >>borneMin;
    cout <<"Entrez la borne maximale: ";
    cin >>borneMax;
    nbAChercher = random(borneMin,borneMax); //Genere le nombre pseudo aléatoire
    tentative=1; //La premiere tentative du joueur va débuter

    //Déroulement de la partie
    do{ //Boucle tant que le joueur dispose encore de tentatives et qu'il n'a pas trouvé le nombre      
                       
        
        cout <<"Saisissez un nombre entre "<<borneMin<<" et "<<borneMax<<". Tentative: "<<tentative<<"/"<<nbTentatives<<" : ";
        cin >> nbSaisi; //Saisie du nombre proposé par le joueur
        
        if (nbSaisi>nbAChercher){ //Si le nombre saisi par le joueur est plus grand que le nombre généré, on écrit "C'est moins !"
            cout <<"C'est moins !\n"<<endl;
        }
        if (nbSaisi<nbAChercher){ //Si le nombre saisi par le joueur est plus petit que le nombre généré, on écrit "C'est plus !"
            cout <<"C'est plus !\n"<<endl;
        }
        if (nbSaisi==nbAChercher){ //Si le nombre saisi par le joueur est le nombre généré, le jeu s'arrête
            break;
        
        }
        tentative++ ; //Incrémentation a la fin de chaque tentative;
    }while(tentative<=nbTentatives);
    //Finalisation de la partie
    if (tentative<=nbTentatives){ //Si le joueur n'a pas dépassé son nombre de tentative autorisé en sortiant de la boucle, il a gagné la partie.
    
        cout <<"B R A V O Vous avez reussi ! Avec "<<tentative<<" tentatives !\n "<<endl;
    }
    else{ // Le joueur à depassé son nombre de tentatives autorisé, il a perdu.
        cout <<"D O M M A G E Vous n'avez pas reussi, le nombre etait : "<<nbAChercher<<endl;
    }
    return 0;
}
