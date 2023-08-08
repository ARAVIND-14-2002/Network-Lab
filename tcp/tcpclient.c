#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void) {
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000];

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Error while creating socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Unable to connect");
        return 1;
    }
    printf("Connected with server successfully\n");

    printf("Enter message: ");
    fgets(client_message, sizeof(client_message), stdin);

    if (send(socket_desc, client_message, strlen(client_message), 0) < 0) {
        perror("Unable to send message");
        return 1;
    }

    if (recv(socket_desc, server_message, sizeof(server_message), 0) < 0) {
        perror("Error while receiving server's message");
        return 1;
    }
    printf("Server's response: %s\n", server_message);

    close(socket_desc);
    return 0;
}
