// On affiche "Hello World!" dans la console
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void compteur(unsigned long int *compteur)
{
    // fermer le mutex
    
    unsigned long tmp;
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        tmp = *compteur;
        tmp++;
        *compteur = tmp;
        pthread_mutex_unlock(&mutex);
    }
    printf("compteur = %lu\n", *compteur);
}


int main()
{
    unsigned long int cpt = 0;
    pthread_t thread1, thread2;
    // pthread_create(&thread1, NULL, (void*)compteur, &cpt);
    // pthread_create(&thread2, NULL, (void*)compteur, &cpt);
    // pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);
    compteur(&cpt);
    printf("valeur de cpt %lu\n",cpt);
    return 0;   
}

// RESULTATS SANS MUTEX :

// compteur = 10242099
// compteur = 10414099
// valeur de cpt 10414099

// real    0m0.161s
// user    0m0.283s
// sys     0m0.020s



// RESULTATS AVEC MUTEX :

// compteur = 19716709
// compteur = 20000000
// valeur de cpt 20000000

// real    0m1.757s
// user    0m1.934s
// sys     0m1.241s


// ET POUR LE FUN :
// compteur = 20000000
// valeur de cpt 20000000

// real    0m0.509s
// user    0m0.461s
// sys     0m0.001s
// CONCLUSION : le plus rapide, c'est les programmes qui marchent pas avec des threads, 
// puis les programmes qui ne font qu'un seul fil de vie,
// puis les programmes threadés avec mutex.