// Programme qui se connecte au serveur et lui demande l'heure
// Compare this snippet from timeServer/timeClient.c:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int creer_socket_client(char *ip, int port){
    int socket_client;
    socket_client = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_client == -1){
        perror("socket_client");
    }
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    inet_aton(ip, &saddr.sin_addr);
    if (connect(socket_client, (struct sockaddr *)&saddr, sizeof(saddr)) == -1){
        perror("connect socker_client");
    }
    return socket_client;
}

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[2]);
    int socket_client = creer_socket_client(argv[1], port);
    if (socket_client == -1){
        perror("creer_socket_client");
        exit(1);
    }
    char buffer[100];

    printf("Entrez une ville : ");
    fgets(buffer, 99, stdin);
    write(socket_client, buffer, strlen(buffer));

    while(1){

        read(socket_client, buffer, 99);
        printf("%s", buffer);
        fgets(buffer, 99, stdin);
        write(socket_client, buffer, strlen(buffer));
    }

    close(socket_client);
    return 0;
}
