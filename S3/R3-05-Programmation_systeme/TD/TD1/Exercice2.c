#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

#define TAILLE 1000000

int main(){
    int tableau[TAILLE]; /* Pour que le tableau soit de taille paire */
    pid_t id;
    int etat;
    int i, valeur;

    printf("valeur à rechercher ? \n");
    scanf("%d", &valeur);

    /* On crée le processus fils */
    id=fork();
    switch (id)
    {
    case -1:
        printf("Impossible")
        exit(EXIT_FAILURE);
        break;
    case 0:
        /* On est dans le fils */
        i=TAILLE/2;
        while (i<TAILLE && tableau[i]!=valeur)
        {
            i++;
            if(i<TAILLE){
                printf("Le fils a été trouvé en %d\n", i);
            }
            else exit(EXIT_FAILURE);
        }
        exit(EXIT_FAILURE);
        break;
    default:
        i=0;
        while (i<TAILLE/2 && tableau[i]!=valeur)
        {
            i++;
            if(i<TAILLE/2){
                printf("Le père a été trouvé en %d\n", i);
            }
            else exit(EXIT_FAILURE);
        }
        break;
    }
}
