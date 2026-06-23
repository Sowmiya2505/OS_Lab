#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    char msg[100];

    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    recvfrom(sockfd, msg, sizeof(msg), 0, NULL, NULL);

    printf("Received: %s\n", msg);

    return 0;
}
