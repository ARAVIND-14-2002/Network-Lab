#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void) {
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[] = "This is server message";

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Error while creating socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind to the port");
        return 1;
    }

    if (listen(socket_desc, 1) < 0) {
        perror("Error while listening");
        return 1;
    }

    printf("Listening for incoming connections...\n");

    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);
    if (client_sock < 0) {
        perror("Can't accept");
        return 1;
    }

    printf("Client connected\n");

    char client_message[2000];
    if (recv(client_sock, client_message, sizeof(client_message), 0) < 0) {
        perror("Couldn't receive");
        return 1;
    }

    printf("Msg from client: %s\n", client_message);

    if (send(client_sock, server_message, strlen(server_message), 0) < 0) {
        perror("Couldn't send");
        return 1;
    }

    close(client_sock);
    close(socket_desc);
    return 0;
}
