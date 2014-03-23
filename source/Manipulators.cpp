// Manipulators.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

// cout example

void main()
{
	using namespace std;
	int i;
	float f;
	cout << "Enter i and f >" << endl;
	cin >> i >> f;
	cout << i << endl << f << endl;
	cout << hex << i << endl;
	cout << oct << i << dec << i << endl;
	cout << showpos << i << endl;
	cout << setbase(16) << i << endl;
	cout << setfill('@') << setw(20) << left << dec << i;
	cout << endl;
	cout.fill('@');
	cout.width(20);
	cout.setf(ios::left, ios::adjustfield);
	cout.setf(ios::dec, ios::basefield);
	cout << i << endl;
	cout << scientific << setprecision(10) << f << endl;
	cout.precision(6);
	cout << f << fixed << endl;
	_getch();
}