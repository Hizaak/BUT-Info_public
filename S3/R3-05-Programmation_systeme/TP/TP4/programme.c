#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

int main(void){
    // on ouvre un pipe
    int fd[2];
    pipe(fd);
    // on fork
    int pid = fork();
    if (pid == 0){
        char c;
        while(c!='$'){
            read(fd[0], &c, 1);
            
            printf("le char lu est : %c\n", c);
        }   
        printf("Fils : je quitte\n");
    }
    else{
        char c;
        while(c!='$'){
            c = getchar();
            write(fd[1], &c, 1);
        }
        printf("Pere : je quitte\n");
    }

}