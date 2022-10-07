/*
Programme : Jeu du pendu
But :  trouver le mot caché avant que le pendu soit completé
Date de dernière modification : 3 octobre 2021
Auteur : Nicolas DARGAZANLI & Alexandre MAURICE
Remarques :
*/

#include <iostream>
#include "game-tools.h"

using namespace std;


int main(void)
{   
    //Variables 
    int idxtheme;              // Indice du thème que l'utilisateur à choisie
    char lettre ;              // Lettre proposé par le joueur
    string motcache;           // Mot caché qui se revelera au fur et a mesure de la partie
    string mot="" ;            // Mot à deviner
    short unsigned int i;      // Indice pour creer le nombre caché
    int tentativeRes=7 ;       // Nombre de tentative que le joueur possède
    string lettreIncorrect=""; // Toute les lettres incorrectes deja proposé par le joueur
    bool trouve;               // true si la lettre saisie est dans le mot
    
    



    //creation des tableaux de mots pouvant être proposé
    string informatique[10]={"ordinateur","programme","logiciel","algorithme","compilation","processeur","moniteur","peripherique","binaire","memoire"};
    string mathematiques[10]={"addition","operation","arithmetique","exponentielle","proportionnalite","fraction","arrangement","divisibilite","logarithme","multiplicite"};
    string cinema[10]={"godzilla","shining","avengers","tenet","spiderman","aquaman","jumanji","ironman","greenland","interstellar"};
    
    //Affichage du nom du jeu
    cout<<"**Jeu du pendu**\n\n";

    //Selection du mot à deviner en fonction du theme : verifié
    do{
        cout<<"\n[1] Informatique\n[2] Mathematiques\n[3] Cinema\n\nChoisissez un theme:";
        cin>>idxtheme;
        switch (idxtheme)
        {
        case 1:
            mot=informatique[random(0,9)];
            break;
        case 2:
            mot=mathematiques[random(0,9)];
            break;
        case 3:
            mot=cinema[random(0,9)];
            break;
        
        default:
            cout<<"Theme non reconnu...recommencez"<<endl;
            break;
        }
    }while(mot=="");

    
    //Genere le motcache en fonction du nombre de lettre du mot a deviner
    for (i = 0; i < mot.size(); i++)
    {
        motcache+='-'; //On ajoute un '-' jusqu'a ce que la taille des deux mots soit égale
    }
    // Debut de la partie
    while (tentativeRes>0 && motcache!=mot)
    {
        effacer();                          //Efface le terminal
        cout<<"**Jeu du pendu**\n"<<endl;   //Le nom du jeu sera toujours visible
        cout<<"Le mot a trouver : "<<motcache<<"\n"<<endl;
        if (tentativeRes>4){
            afficherTexteEnCouleur("Nombre de coups restant : ",vert);
            afficherNombreEnCouleur(tentativeRes,vert,true);
        }
        if (tentativeRes<=4 && tentativeRes>=2){
            afficherTexteEnCouleur("Nombre de coups restant : ",violet);
            afficherNombreEnCouleur(tentativeRes,violet,true);
        }
        if (tentativeRes==1){
            afficherTexteEnCouleur("Nombre de coups restant : ",rouge);
            afficherNombreEnCouleur(tentativeRes,rouge,true);
        }

        cout<<"Entrez une lettre : ";
        cin>>lettre;
        trouve=false;
        
        if (lettreIncorrect.find(lettre)== string::npos && motcache.find(lettre)== string::npos){
            
            for (i = 0; i < mot.size(); i++) 
            {
                if (mot[i]==lettre){
                    motcache[i]=lettre;
                    trouve=true;    
                }
            }
            if(trouve){
                cout<<"La lettre "<<lettre<<" EST presente dans le mot :-) "<<endl;

            }
            else{
                cout<<"La lettre n'est PAS presente dans le mot :-( "<<endl;
                lettreIncorrect+=lettre;
                tentativeRes--;
            }}
        else{ 
            if (lettreIncorrect.find(lettre)!= string::npos){
                cout<<"Vous avez deja essaye cette lettre et elle n'est toujours pas dans le mot..."<<endl;
                tentativeRes--;}

            if (motcache.find(lettre)!=string::npos){
                cout<<"Vous avez deja trouve cette lettre...Essayez en d'autres :)"<<endl;}
            }

        pause(2);
        
    }
    effacer();
    cout<<"**Jeu du pendu**\n"<<endl;   //Le nom du jeu sera toujours visible
    if (motcache==mot){
        afficherTexteEnCouleur("B R A V O :)\nVous avez gagne\nVous avez trouve le mot cache !",vert,true);}
    else{
        afficherTexteEnCouleur("P E R D U :(\nOh Non...\nOn dirait que vous n'avez pas trouve le mot cache",rouge,true);}
    cout<<"Le mot etait : ";afficherTexteEnCouleur(mot,bleu,true);
    return 0;
}
