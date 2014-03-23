// 11.11.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

int main()
{
	string name;
	name = "E:\\reverse.txt";
	fstream fs(name.c_str());
	if (!fs) error("fs error");
	string str;
	getline(fs, str);

	fs.seekg(0);
	for (int i = str.size() - 1; i >= 0; --i)
	{
		fs << str[i];
	}
	return 0;
}