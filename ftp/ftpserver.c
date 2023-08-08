#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERV_TCP_PORT 5035
#define MAX 60

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char filename[MAX], buffer[4096];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);
    socklen_t clength = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clength);
    close(sockfd);

    if (read(newsockfd, filename, MAX) < 0) {
        perror("Error reading filename");
        exit(EXIT_FAILURE);
    }
    printf("\nClient message\n File Name : %s\n", filename);

    FILE *f1 = fopen(filename, "r");
    if (f1 == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), f1) != NULL) {
        write(newsockfd, buffer, MAX);
    }

    fclose(f1);
    printf("\nFile Transferred\n");

    close(newsockfd);
    return 0;
}
