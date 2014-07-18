// SERVER

#include <string.h>
#include <iostream>
#include <QtSql>
#include <QtSql/QSqlQuery>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    int sock, listener;
    struct sockaddr_in addr;
    char message[5];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3423);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

    while(1)
    {
        sock = accept(listener, NULL, NULL);
        if(sock < 0)
        {
            perror("accept");
            exit(3);
        }

        while(1)
        {
            bytes_read = recv(sock, message, 5, 0);
            if(bytes_read <= 0) break;
            std::cout << message;
            //send(sock, message, bytes_read, 0);
        }

        close(sock);
    }

    return 0;
}
