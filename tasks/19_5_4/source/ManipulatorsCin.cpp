// ManipulatorsCin.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>

void main()
{
	using namespace std;

	// EXAMPLE 1

	int i;
	float f;
	char c;
	cout << "Enter i,f,c and then input the string >" << endl;
	cin >> i >> f >> c;
	cout << i << endl << f << endl << c << endl;
	
	// EXAMPLE 2

	char p[50];
	cin >> ws >> p;
	cout << p << endl;
	cin.seekg(0);
	cin.getline(p, 10);
	cout << p << endl;
	_getch();
}