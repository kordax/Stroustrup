// 10.8.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

class Reading
{
public:
	string str;
};

int main()
{
	string file1, file2, output;
	string iname1, iname2, oname;
	cout << "1 file: ";
	cin >> iname1;
	cout << "2 file: ";
	cin >> iname2;
	ifstream is1 (iname1.c_str());
	ifstream is2 (iname2.c_str());
	is1 >> file1;
	is2 >> file2;
	output = file1 + file2;
	cout << "Output file: ";
	cin >> oname;
	ofstream os(oname.c_str());
	os << output;
	return 0;
}

