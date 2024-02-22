#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_SIZE 1024
#define MAX_CHANNEL_NAME 50

typedef struct {
    int socket;
    struct sockaddr_in address;
    char *pseudo;
    char *channel;
} ClientInfo;

typedef struct {
    char name[MAX_CHANNEL_NAME];
    FILE *file;
} ChannelInfo;

// Liste des clients connectés
ClientInfo *clients[MAX_CLIENTS];

// Liste des channels
ChannelInfo *channels[MAX_CLIENTS];
int numChannels = 0;

int findChannelByName(char *name) {
    for (int i = 0; i < numChannels; i++) {
        if (strcmp(channels[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteAllFiles() {
    char command[100];
    snprintf(command, sizeof(command), "rm -rf ./channels/*");
    system(command);
}

void *handle_client(void *arg) {
    ClientInfo *client_info = (ClientInfo *)arg;
    char buffer[MAX_MESSAGE_SIZE];
    int bytes_received;
    client_info->pseudo = "";
    char channel_name[MAX_CHANNEL_NAME] = "";

    char client_address[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(client_info->address.sin_addr), client_address, INET_ADDRSTRLEN);

    while (strcmp(client_info->pseudo, "") == 0) {
        bytes_received = recv(client_info->socket, buffer, sizeof(buffer), 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';

            int pseudo_already_used = 0;
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] != NULL && strcmp(clients[i]->pseudo, buffer) == 0) {
                    pseudo_already_used = 1;
                    send(client_info->socket, "0", sizeof("0"), 0);
                    break;
                }
            }

            if (!pseudo_already_used) {
                // Ajouter le client à la liste des clients connectés
                clients[client_info->socket] = client_info;

                client_info->pseudo = (char *)malloc(strlen(buffer) + 1);
                strcpy(client_info->pseudo, buffer);

                printf("%s a rejoint le chat !\n", client_info->pseudo);
                send(client_info->socket, "1", sizeof("1"), 0);

                // Envoyer la liste des channels au client
                for (int i = 0; i < numChannels; i++) {
                    send(client_info->socket, channels[i]->name, sizeof(channels[i]->name), 0);
                }

                // Attendre le nom du channel que le client veut rejoindre
                bytes_received = recv(client_info->socket, channel_name, sizeof(channel_name), 0);
                if (bytes_received > 0) {
                    channel_name[bytes_received] = '\0';

                    // Vérifier si le channel existe déjà
                    int channel_index = findChannelByName(channel_name);
                    if (channel_index == -1) {
                        ChannelInfo *new_channel = (ChannelInfo *)malloc(sizeof(ChannelInfo));
                        strcpy(new_channel->name, channel_name);
                        snprintf(buffer, sizeof(buffer), "./channels/%s.txt", new_channel->name);
                        new_channel->file = fopen(buffer, "a+");
                        channels[numChannels++] = new_channel;
                        // Envoyer "1" au client pour lui indiquer que le channel a été créé
                        send(client_info->socket, "1", sizeof("1"), 0);
                    } else {
                        ChannelInfo *new_channel = (ChannelInfo *)malloc(sizeof(ChannelInfo));
                        snprintf(buffer, sizeof(buffer), "./channels/%s.txt", channel_name);
                        new_channel->file = fopen(buffer, "r");
                        // Envoyer "2" au client pour lui indiquer qu'il se connecte à un channel existant
                        send(client_info->socket, "2", sizeof("2"), 0);

                        // Envoyer l'intégralité du fichier au client (système d'historique)
                        while (fgets(buffer, sizeof(buffer), new_channel->file) != NULL) {
                            send(client_info->socket, buffer, strlen(buffer), 0);
                        }
                        client_info->channel = (char *)malloc(strlen(channel_name) + 1);
                        strcpy(client_info->channel, channel_name);
                        fclose(new_channel->file);
                    }
                }
            }
        } else {
            perror("Erreur lors de la réception du message du client");
            break;
        }
    }

    while ((bytes_received = recv(client_info->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';

        char message[MAX_MESSAGE_SIZE];
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        char time[9];
        strftime(time, sizeof(time), "%H:%M:%S", t);
        strcpy(message, "[");
        strcat(message, time);
        strcat(message, "] [");
        strcat(message, client_info->pseudo);
        strcat(message, "] ");
        strcat(message, buffer);

        // Écrire le message dans le fichier du channel
        int channel_index = findChannelByName(channel_name);
        if (channel_index != -1) {
            fprintf(channels[channel_index]->file, "%s\n", message);
            fflush(channels[channel_index]->file);
        }

        // maintenant il faut envoyer le message à tous les clients en vérifiant qu'ils sont bien dans le même channel que le client qui a envoyé le message
        for (int i = 0; i < MAX_CLIENTS; i++) {
            
            if (clients[i] != NULL && strcmp(clients[i]->channel, channel_name) == 0 && clients[i]->socket != client_info->socket) {
                send(clients[i]->socket, message, strlen(message), 0);
            }
        }
    }

    // Fermer la connexion avec le client
    close(client_info->socket);
    free(client_info);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    deleteAllFiles();

    int server_socket, client_socket;
    unsigned short port = atoi(argv[1]);
    struct sockaddr_in server_address, client_address;
    pthread_t client_threads[MAX_CLIENTS];
    int thread_count = 0;

    // Création de la socket du serveur
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Erreur lors de la création de la socket du serveur");
        exit(EXIT_FAILURE);
    }

    // Configuration de l'adresse du serveur
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Liaison de la socket à l'adresse et au port spécifiés
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Erreur lors de la liaison de la socket à l'adresse et au port spécifiés");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Mise en écoute de la socket
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Erreur lors de la mise en écoute de la socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Serveur en attente de clients sur le port %d...\n", port);

    // Boucle principale pour accepter les clients
    while (1) {
        // Accepter la connexion d'un client
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Erreur lors de l'acceptation de la connexion du client");
            continue;
        }

        // Créer un thread dédié pour gérer la communication avec le client
        ClientInfo *client_info = (ClientInfo *)malloc(sizeof(ClientInfo));
        client_info->socket = client_socket;
        memcpy(&(client_info->address), &client_address, sizeof(client_address));

        if (pthread_create(&client_threads[thread_count], NULL, handle_client, (void *)client_info) != 0) {
            perror("Erreur lors de la création du thread client");
            close(client_socket);
            free(client_info);
            continue;
        }

        thread_count++;

        if (thread_count >= MAX_CLIENTS) {
            fprintf(stderr, "Nombre maximal de clients atteint. Fermeture du serveur.\n");
            break;
        }
    }

    // Attente de la fin de tous les threads clients
    for (int i = 0; i < thread_count; i++) {
        pthread_join(client_threads[i], NULL);
    }

    // Fermeture de la socket du serveur
    close(server_socket);

    return 0;
}
