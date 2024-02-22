#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_MESSAGE_SIZE 1024

// Structure pour stocker les données du thread d'écoute
struct ThreadData {
    int client_socket;
};

// Fonction pour le thread d'écoute
void *listen_to_server(void *arg) {
    struct ThreadData *thread_data = (struct ThreadData *)arg;
    int client_socket = thread_data->client_socket;
    char buffer[MAX_MESSAGE_SIZE];

    while (1) {
        // Recevoir la réponse du serveur
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("\33[2K\r");
            printf("%s\n", buffer);
            printf("\rSaisissez un message : \n");
        } else {
            perror("Erreur lors de la réception de la réponse du serveur\n");
            break;
        }
    }

    // Fermer le socket du client lorsque le thread se termine
    close(client_socket);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int client_socket;
    char buffer[MAX_MESSAGE_SIZE];

    // Création de la socket du client
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Erreur lors de la création de la socket du client\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;

    // Configuration de l'adresse du serveur
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connexion au serveur
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Erreur lors de la connexion au serveur\n");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connecté au serveur %s:%s\n", argv[1], argv[2]);

    int isPseudoOk = 0;
    while (!isPseudoOk) {
        // Demande de saisie du pseudo
        printf("Saisissez votre pseudo : \n");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        send(client_socket, buffer, strlen(buffer), 0);

        // Réception de la réponse du serveur
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            if (strcmp(buffer, "1") == 0) {
                isPseudoOk = 1;
            } else {
                printf("Pseudo déjà utilisé, réessayez :\n");
            }
        } else {
            perror("Erreur lors de la réception de la réponse du serveur\n");
            break;
        }
    }

    // Demande de saisie du channel
    printf("Saisissez le nom du channel : \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    send(client_socket, buffer, strlen(buffer), 0);

    // Réception de la réponse du serveur
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        // Si buffer vaut l'entier 1 le channel a été créé, si buffer vaut l'entier 2 le channel existe déjà et on s'y connecte
        if (strcmp(buffer, "1") == 0) {
            printf("Channel créé\n");
        } else if (strcmp(buffer, "2") == 0) {
            printf("Le channel existait déjà, vous vous êtes connecté !\n");
        } else {
            perror("Erreur lors de la réception de la réponse du serveur\n");
        }
    }
    
    struct ThreadData thread_data;
    thread_data.client_socket = client_socket;

    pthread_t listen_thread;
    if (pthread_create(&listen_thread, NULL, listen_to_server, (void *)&thread_data) != 0) {
        perror("Erreur lors de la création du thread d'écoute");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Boucle pour envoyer des messages au serveur
    while (1) {
        printf("Saisissez un message: \n");
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = '\0';
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Attendre que le thread d'écoute se termine
    pthread_join(listen_thread, NULL);

    return 0;
}
