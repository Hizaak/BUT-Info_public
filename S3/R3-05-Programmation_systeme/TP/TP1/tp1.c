#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void question1(){
    
    // Afficher le numéro de processus
    printf("Je suis le processus numéro : %d\n", getpid());

    // Créer un processus fils
    pid_t pid = fork();
    switch(pid){
        case -1:
            printf("Erreur lors de la création du processus fils\n");
            exit(1);
        case 0:
            printf("Je suis le processus fils numéro : %d, et mon père est le processus numéro : %d\n", getpid(), getppid());
            break;
        default:
            printf("Je suis le processus père numéro : %d, et mon fils est le processus numéro : %d\n", getpid(), pid);
            break;
    }
}

void question2(){
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Erreur lors de la création du processus fils\n");
        exit(1);
    } else if (pid == 0) {
        // Processus fils
        printf("Processus fils : Affichage des 10 premiers nombres pairs\n");
        for (int i = 2; i <= 20; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        // Processus père
        printf("Processus père : Affichage des 10 premiers nombres impairs\n");
        for (int i = 1; i <= 19; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
        // Exécution de la commande ps -l
        system("ps -l");
    }

}

int main(int argc, char *argv[])
{
    question2();
    return 0;
}