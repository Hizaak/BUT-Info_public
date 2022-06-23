#include "sousProgrammes.h"
#include "fichierTexte.h"
#include "pile.h"
#include <iostream>
using namespace std;

void afficherFichierTexte(string nomSysFic)
{
      //Préparer le fichier
      UnFichierTexte fic;
      associer(fic, nomSysFic); //Lie le nom logique et le nom système
      ouvrir(fic,consultation); //Ouvre le fichier à partir de son nom logique
      bool fdf;
      string ligne;
      //Parcours complet pour l'affichage
      while(true)
      {
            //tentative de lecture
            lireLigne(fic,ligne,fdf);
            if(fdf)
            {
                  break;
            }
            cout<<ligne<<endl;
      }
      fermer(fic);
}


void afficherInverseFichierTexte(string nomSysFic)
{
      //Préparer le fichier
      UnePile maPile;
      UnFichierTexte fic;
      associer(fic, nomSysFic); //Lie le nom logique et le nom système
      ouvrir(fic,consultation); //Ouvre le fichier à partir de son nom logique
      bool fdf;
      string ligne;
      while(true)
      {
            lireLigne(fic,ligne,fdf);
            if(fdf)
            {
                  break;
            }
            empiler(maPile,ligne);
      }
      while(!estVide(maPile))
      {
            string stockage;
            depiler(maPile,stockage);
            cout<<stockage<<endl;
      }
            
}

void etendreFichierTexte (string nomSysFicSource, string nomSysFicCible)
{
      //Préparer le fichier
      UnFichierTexte ficSource;
      UnFichierTexte ficCible;
      associer(ficSource, nomSysFicSource); //Lie le nom logique et le nom système
      ouvrir(ficSource,consultation); //Ouvre le fichier à partir de son nom logique
      associer(ficCible, nomSysFicCible); //Lie le nom logique et le nom système
      ouvrir(ficCible,extension); //Ouvre le fichier à partir de son nom logique
      string ligne;
      bool fdf=false;
      //Parcours complet pour l'affichage
      while(!fdf)
      {
            //tentative de lecture
            lireLigne(ficSource,ligne,fdf);
            ecrireLigne(ficCible, ligne);
      }
      //Préparer le fichier qui va se faire élargir
      
      fermer(ficSource);
      fermer(ficCible);
}

void viderFichierTexte(string nomSysFic)
{
      //Préparer le fichier
      UnFichierTexte fic;
      associer(fic, nomSysFic); //Lie le nom logique et le nom système
      ouvrir(fic,creation); //Ouvre le fichier à partir de son nom logique
}