#include <iostream>
#include <QtSql>
#include <QtSql/QSqlQuery>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <QtDebug>

using namespace std;

int conn_01 = socket(AF_INET, SOCK_STREAM, 1);

int main()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("stack.beget.ru");
    db.setDatabaseName("dremor_wp");
    db.setUserName("dremor_wp");
    db.setPassword("123456a");
    bool ok = db.open();

    if (ok)
    {
        cout << "ok" << endl;
        cout << AF_INET << endl << SOCK_STREAM << endl;
    }


}
