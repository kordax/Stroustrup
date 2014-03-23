// InputOutputFiles_Binary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>

void main()
{
	using namespace std;

	struct Blocknotes
	{
		char name[30];
		int age;
		char phone[15];
	}
	b[2] = {
		"Smith", 123456, "45",
		"Kolly", 456789, "50"
	};

	ofstream FILE;
		FILE.open("Block", ios::binary);
	for (int i = 0; i < 2; i++)
		FILE.write((char *) &b[i], sizeof(b[i]));
		FILE.close();

	ifstream FILE1;
	FILE1.open("Block", ios::binary);
	Blocknotes bb[2];
	int i = 0;
	while (!FILE1.eof())
	{
		if (i == 2)
			goto m;
		FILE1.read((char *) &bb[i], sizeof(bb[i]));
		cout << "string" << i << " " << bb[i].name << " " << bb[i].phone << " " << bb[i].age << endl;
		i++;
	}
m: FILE1.close();
	system("DEL BLOCK");
	_getch();
}