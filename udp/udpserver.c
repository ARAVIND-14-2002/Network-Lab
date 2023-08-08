#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("[-]socket error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4455);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("[-]bind error");
        exit(1);
    }

    addr_size = sizeof(client_addr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &client_addr, &addr_size);
    printf("[+]Data recv: %s\n", buffer);

    strcpy(buffer, "Welcome to the UDP server");
    sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &client_addr, sizeof(client_addr));
    printf("[+]Data send: %s\n", buffer);

    close(sockfd);
    return 0;
}
