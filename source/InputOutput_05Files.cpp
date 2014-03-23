// InputOutput_05Files.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#define DelKey 'n'
#define maxline 1000

int main()
{
	using namespace std;

	ofstream FILE;
	FILE.open("E:\\a.txt", ios::out);
	char p[maxline];
	int i, pos;
	for (i = 0; i < 2; i++)
		FILE << "string " << i;
	FILE.close();

	ifstream FILE1;
	FILE1.open("E:\\a.txt");
	FILE1.seekg(0);
	if (!FILE1)
		return(0);
	while (!FILE1.eof())
	{
		FILE1 >> p >> i;
		cout << p << i << endl;
	}
	FILE1.close();
	_getch();

	ifstream FILE2;
	char c;
	FILE2.open("E:\\a.txt");
	if (!FILE2)
		return(0);
	while (!FILE2.eof())
	{
		c = FILE2.peek();
		streamoff cgp = FILE2.tellg();
		if (c == DelKey)
		{
			pos = cgp + 1;
			FILE2.seekg(pos);
			continue;
		}
		FILE2.get(c);
		cout << c;
	}

	cout << endl;
	FILE2.close();
	_getch();
	system("DEL E:\\a.txt");
}
