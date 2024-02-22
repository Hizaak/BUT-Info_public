#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Utilisation : %s <port>\n", argv[0]);
        exit(1);
    }

    int server_port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Erreur lors de la création du socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Erreur lors de la liaison du socket au port");
        close(server_socket);
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("Erreur lors de la mise en écoute du socket");
        close(server_socket);
        exit(1);
    }

    printf("Serveur en écoute sur le port %d...\n", server_port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket == -1) {
            perror("Erreur lors de l'acceptation de la connexion entrante");
            continue;  // Passer à la prochaine connexion
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
        printf("Nouvelle connexion acceptée de %s:%d\n", client_ip, ntohs(client_addr.sin_port));

        // Réception du message de l'utilisateur
        char message[100];
        int bytes_received = recv(client_socket, message, sizeof(message), 0);
        if (bytes_received == -1) {
            perror("Erreur lors de la réception du message de l'utilisateur");
            close(client_socket);
            continue;  // Passer à la prochaine connexion
        }

        message[bytes_received] = '\0';
        printf("Message reçu de l'utilisateur : %s\n", message);

        // Traitement du message (multiplication par 2)
        int number = atoi(message);
        int response = number * 2;
        char response_message[100];
        snprintf(response_message, sizeof(response_message), "Réponse : %d\n", response);

        // Envoi de la réponse à l'utilisateur
        if (send(client_socket, response_message, strlen(response_message), 0) == -1) {
            perror("Erreur lors de l'envoi de la réponse à l'utilisateur");
        }

        // Fermez la socket client lorsque vous avez terminé.
        close(client_socket);
    }

    return 0;
}
