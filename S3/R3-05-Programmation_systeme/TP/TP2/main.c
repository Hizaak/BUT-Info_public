// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <pthread.h>

// void afficherPoint(void){
//     while (1)
//     {
//         printf(".\n");   
//         sleep(1);   
//     }
// }

// void attendreSaisie(void){

//     printf("Appuyez sur une touche pour quitter\n");
//     getchar();
//     printf("Merci !\n");
// }

// int main(){
//     pthread_t thread1;
//     pthread_t thread2;

//     pthread_create(&thread1, NULL, (void *)afficherPoint, NULL);
//     pthread_create(&thread2, NULL, (void *)attendreSaisie, NULL);

//     printf("Les deux threads sont lances\n");
    
    
//     pthread_join(thread2, NULL);

//     printf("On va s'arrêter là\n");
//     return 0;
// }

