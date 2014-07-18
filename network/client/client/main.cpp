// CLIENT

#include <string.h>
#include <iostream>
#include <QtSql>
#include <QtSql/QSqlQuery>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

//==========================

namespace kordax
{

struct token
{
private:
    string type;
    char* elem[];

public:
    istream& operator>> (istream& is);
    ostream& operator<< (ostream& os);
};

bool parse_input(const string& input)
{
    for (int i = 0; i < input.size(); ++i)
        if (!isdigit(input[i]) && !isalpha(input[i])) return false;
    return true;
}

}

istream& kordax::token::operator>> (istream& is)
{
    char ch;
    int cnt = 0;
    while (is)
    {
        is >> ch;
        this->type[cnt] = ch;
        cnt++;
    }
    return is;
}

//==========================

void authorization(string& username, string& password)
{
    std::cout << "Enter your nickname: ";
    cin >> username;
    if (!kordax::parse_input(username)) cout << "Wrong symbols in username!" << endl;
    std::cout << endl;
    std::cout << "Enter your password: ";
    cin >> password;
    if (!kordax::parse_input) cout << "Wrong symbols in username!" << endl;
    //username = kordax::readline();
    std::cout << endl;

    return;
}

void main_loop(int socket)
{
    char message[] = "test";
    char buffer[sizeof(message)];

    cout << ':';
    cin >> message;

    send(socket, message, sizeof(message), 0);
    recv(socket, buffer, sizeof(message), 0);
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

    cout << "Succesfully connected to server!" << endl;
    cout << "Now eat shit, faggot and type your stuff!" << endl;

    main_loop(sock);

    //printf(buf);
    close(sock);

    return 0;
}
