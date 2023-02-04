#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <phthread.h>

#define TAILLE 1000000
int tableau[TAILLE]; /* Pour que le tableau soit de taille paire */
int valeurCherchee;

int pthread_create(pthread_t * thread, pthread_attr_t * attr, void * (*start_routine)(void *), void * arg);

void *recherche(void *arg){
    int i = (int)arg;
    int j = i + TAILLE/2;
    while (i < j && tableau[i] != valeurCherchee)
    {
        i++;
        if(i < j){
            printf("Le fils a été trouvé en %d\n", i);
        }
        else exit(EXIT_FAILURE);
    }
    exit(EXIT_FAILURE);
}


