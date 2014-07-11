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

struct token_stream
{
public:
    string type;
    char elem;
};

namespace kordax
{

int parse_input(string& input)
{

}

}
void authorization(string& username, string& password)
{
    std::cout << "Enter your nickname: ";
    //username = kordax::readline();
    std::cout << endl;
    std::cout << "Enter your password: ";
    //username = kordax::readline();
    std::cout << endl;

    return;
}

int main()
{
    string username, password;

    authorization(username, password);

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
