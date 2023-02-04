// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <sys/wait.h>
// // #include <phthread.h>
// #include <signal.h>

// #define DELAI 15
// #define ATTENTE 50

// void relance(int sig){
//     printf("Alors ca vient ?");
// }

// int main(void){
//     char c;
//     struct sigaction sig_relance,ancien;
//     sig_relance.sa_handler=relance;
//     sig_relance.sa_flags=SA_RESTART;
//     sigemptyset(&sig_relance.sa_mask);
//     sigaction(SIGALRM,&sig_relance,&ancien);
//     alarm(DELAI);
//     printf("Appuyez sur une touche pour continuer\n");
//     c=getchar();
//     alarm(0);
//     sigaction(SIGALRM,&ancien,NULL);

//     printf("Début du calcul\n");
//     sleep(ATTENTE);
//     printf("Fin du calcul\n");

//     exit(EXIT_SUCCESS);
//     return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
// #include <phthread.h>
#include <signal.h>

#define DELAI 15
#define ATTENTE 50
#define DELAI2 30

void relance(int sig){
    printf("Alors ca vient ?");
}

int main(void){
    char c;
    struct sigaction sig_relance,ancien;
    sig_relance.sa_handler=relance;
    sig_relance.sa_flags=SA_RESTART;
    sigemptyset(&sig_relance.sa_mask);
    sigaction(SIGALRM,&sig_relance,&ancien);
    alarm(DELAI);
    printf("Appuyez sur une touche pour continuer\n");
    c=getchar();
    alarm(0);
    sigaction(SIGALRM,&ancien,NULL);

    printf("Début du calcul\n");
    sleep(ATTENTE);
    printf("Fin du calcul\n");

    exit(EXIT_SUCCESS);
    return 0;
}