#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int creer_serveur(int port){
    int socket_serveur;
    socket_serveur = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_serveur == -1){
        perror("socket_serveur");
    }
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port); 
    saddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(socket_serveur, (struct sockaddr *)&saddr, sizeof(saddr)) == -1){
        perror("bind socker_serveur");
    }
    if (listen(socket_serveur, 10) == -1){
        perror("listen socket_serveur");
    }
    return socket_serveur;
}

char* chiffreCesar(char* message, int decalage){
    int i;
    for(i=0;i<strlen(message);i++){
        message[i] = (message[i] - 'a' + decalage) % 26 + 'a';
    }
    return message;
}

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[2]);
    int socket_serveur = creer_serveur(port);
    if (socket_serveur == -1){
        perror("creer_serveur");
        exit(1);
    }
    while(1){
        int socket_client = accept(socket_serveur, NULL, NULL);
        if (socket_client == -1){
            perror("accept");
        }
        char buffer[100];
        int res = read(socket_client, buffer, 99);
        if (res == -1){
            perror("read socket_client");
        }
        if (res == 0){
            break;
        }
        int decalage = atoi(buffer);
        if (decalage == 0){
            close(socket_client);
            continue;
        }
        char *message = "Décalage pris en compte\n";
        write(socket_client, message, strlen(message));
        while(1){
            int res = read(socket_client, buffer, 99);
            if (res == -1){
                perror("read socket_client");
            }
            if (res == 0){
                break;
            }
            buffer[res] = '\0';
            char* messageChiffre = chiffreCesar(buffer, decalage);
            printf("%s\n", messageChiffre);

            write(socket_client, buffer, strlen(buffer));
        }
        
        close(socket_client);
    }
}

