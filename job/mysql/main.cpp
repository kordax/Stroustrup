#include <iostream>
#include <my_global.h>
#include <mysql.h>
#include "string"

using namespace std;

string host, user, base, pass;

const char* phost;
const char* puser;
const char* pbase;
const char* ppass;

int main()
{
MYSQL conn;

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
	cout << "Error: can't connect to MySQL server\n";
else
	cout << "Successfully connected!";

MYSQL* marker = &conn;

cout << endl;
cout << mysql_stat(marker);
cout << endl;
}
