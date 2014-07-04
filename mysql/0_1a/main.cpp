#include <iostream>
#include <QtSql>
#include <QtSql/QSqlQuery>
#include <string.h>

using namespace std;

int main()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("mydb");
    db.setHostName("stack.beget.ru");
    db.setDatabaseName("dremor_wp");
    db.setUserName("dremor_wp");
    db.setPassword("123456a");
    bool ok = db.open();

    if (ok)
    {
        cout << "ok";
    }
}
