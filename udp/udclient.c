#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("[-]socket error");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4455);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    strcpy(buffer, "Hello world!");
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*) &server_addr, sizeof(server_addr));
    printf("[+]Data send: %s\n", buffer);

    socklen_t server_len = sizeof(server_addr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &server_addr, &server_len);
    printf("[+]Data recv: %s\n", buffer);

    return 0;
}
