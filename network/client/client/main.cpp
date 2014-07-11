// CLIENT

#include <string.h>
#include <iostream>
#include <QtSql>
#include <QtSql/QSqlQuery>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

char message[] = "Hello there!\n";
char buf[sizeof(message)];

using namespace std;

namespace kordax
{

string readline()
{
    string str;
    char ch;
    while(ch)
    {
        std::cin >> ch;
        if(! isdigit(ch))
        {
            cout << "Error, forbidden symbols!";
            return NULL;
        }
        else str += ch;
    }

    return str;
}
}

int authorization(string& username, string& password)
{
    std::cout << "Enter your nickname: ";
    username = kordax::readline();
    std::cout << endl;
    std::cout << "Enter your password: ";
    username = kordax::readline();
    std::cout << endl;

    return 0;
}

int main()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }

    send(sock, message, sizeof(message), 0);
    recv(sock, buf, sizeof(message), 0);

    printf(buf);
    close(sock);

    return 0;
}
