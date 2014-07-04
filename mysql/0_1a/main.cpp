#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <string.h>

using namespace std;

int main()
{
db = QSqlDatabase::addDatabase("test"); // Вот место, где ты указываешь драйвер. В данном случае я указал Мускуль. Будет другой сервер - укажешь другой
db.setHostName(host);
db.setDatabaseName(dbname);
db.setUserName(user);
db.setPassword("");

if (!db.open())
{
    QMessageBox::critical( // Не получилось соеиниться
        parent,
        QObject::tr("Database Error"),
        db.lastError().text());          // А здесь причина, по которой не удалось соединиться.
    exit(0);
}
}
