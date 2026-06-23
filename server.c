#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, client_fd;
    char msg[100];

    struct sockaddr_in server;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&server, sizeof(server));

    listen(server_fd, 1);

    client_fd = accept(server_fd, NULL, NULL);

    recv(client_fd, msg, sizeof(msg), 0);

    printf("Received: %s\n", msg);

    return 0;
}
