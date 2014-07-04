#include <iostream>
#include <my_global.h>
#include <mysql.h>
#include <string.h>

using namespace std;

  MYSQL_RES *res; // Дескриптор результирующей таблицы
  MYSQL_ROW row; // Массив полей текущей строки

void loop_start(MYSQL &connection, string &input)
{

mysql_options(&connection, MYSQL_SET_CHARSET_NAME, "CP1251");

const char* cinput;
char* test = "SHOW TABLES";

mysql_query(&connection, test);
res = mysql_store_result(&connection);
row = mysql_fetch_row(res);
cout << mysql_error(&connection);
return;

while(true)
{
//if (cin >> input && input == "quit" || input == "exit" || input == "leave") return;
cinput = input.c_str();
if (mysql_query(&connection, cinput) != 0)
{
system("echo '\E[40;31m'");
string error_output;
error_output = cinput;
cout << mysql_error(&connection);
cout << " DEBUG INFO: #" << mysql_query(&connection, cinput);
cout << " PARSED STRING: " << error_output << '\n';
system("echo '\E[40;33m'");
}
input.clear();
}
}

string host, user, base, pass;

const char* phost;
const char* puser;
const char* pbase;
const char* ppass;

int main()
{
MYSQL conn; // Дескриптор соединения

if(!mysql_init(&conn))
cout << "Error: can't create MySQL-decriptor \n";

cout << "hostname: ";
cin >> host;
cout << "user: ";
cin >> base;
cout << "password: ";
cin >> pass;

phost = host.c_str();
puser = base.c_str();
pbase = base.c_str();
ppass = pass.c_str();

if(!mysql_real_connect(&conn, phost, puser, ppass, pbase, 0, NULL, 0))
{
cout << "Error: can't connect to MySQL server\n";
system("echo '\033[0m'");
return 1;
}
else
cout << "Successfully connected!";

cout << endl;
system("echo '\E[40;33m'");
cout << mysql_stat(&conn);
cout << endl;
//system("echo '\033[0m'");

string inp;

loop_start(conn, inp);
system("echo '\033[0m'");
}
