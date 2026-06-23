#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    send(sockfd, "Hello TCP", 10, 0);

    return 0;
}
