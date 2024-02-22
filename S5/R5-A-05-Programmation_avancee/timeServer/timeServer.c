#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "time.h"

//  Programme qui attend une connexion, que le cient donne sa ville, et lui renvoie l'heure en fonction de sa ville
// Tableau de villes et de fuseaux horaires (en heures de différence avec UTC), avec une structure de données de type dictionnaire
// Par exemple : Paris, 2

struct ville{
    char *nom;
    int fuseau;
};

// mise des villes dans un tableau


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

    int socket_client;
    struct sockaddr_in caddr;
    socklen_t caddr_len = sizeof(caddr);
    char buffer[100];
    // Vérifier quelle est la ville du client
    socket_client = accept(socket_serveur, (struct sockaddr *)&caddr, &caddr_len);
    if (socket_client == -1){
        perror("accept socket_client");
    }
    read(socket_client, buffer, 99);
    int ville = atoi(buffer);
    // dire quelle heure il est dans cette ville
    time_t timestamp = time(NULL);
    struct tm *tm = localtime(&timestamp);
    int heure = tm->tm_hour;
    int minute = tm->tm_min;
    int seconde = tm->tm_sec;
    heure += ville;
    heure %= 24;
    sprintf(buffer, "Il est %d:%d:%d à %s\n", heure, minute, seconde, villes[ville]);
    write(socket_client, buffer, strlen(buffer));
    close(socket_client);
    close(socket_serveur);
    return 0;

}