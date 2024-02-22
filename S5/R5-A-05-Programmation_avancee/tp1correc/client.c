#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Utilisation : %s <adresse IP du serveur> <port>\n", argv[0]);
        exit(1);
    }

    const char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Erreur lors de la création du socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Erreur lors de la conversion de l'adresse IP");
        close(client_socket);
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Erreur lors de la connexion au serveur");
        close(client_socket);
        exit(1);
    }

    printf("Connecté au serveur %s:%d\n", server_ip, server_port);

    // Envoi d'un message au serveur
    char message[100];
    printf("Entrez un message à envoyer au serveur : ");
    fgets(message, sizeof(message), stdin);

    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Erreur lors de l'envoi du message au serveur");
        close(client_socket);
        exit(1);
    }

    // Réception de la réponse du serveur
    char response[100];
    int bytes_received = recv(client_socket, response, sizeof(response), 0);
    if (bytes_received == -1) {
        perror("Erreur lors de la réception de la réponse du serveur");
        close(client_socket);
        exit(1);
    }

    response[bytes_received] = '\0';
    printf("Réponse du serveur : %s\n", response);

    // Fermez la socket client lorsque vous avez terminé.
    close(client_socket);

    return 0;
}
