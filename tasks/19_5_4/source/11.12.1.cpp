// 11.12.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

int main()
{
	vector<string> words;

	string name;
	name = "E:\\reverse.txt";
	fstream fs(name.c_str());
	if (!fs) error("fs error");
	string str;
	while (fs >> str)
	{
	words.push_back(str);
	}
	fs.close();
	fs.open(name.c_str(), ios_base::out);
	fs.seekg(0);
	for (int i = words.size() - 1; i >= 0; --i)
	{
		fs << words[i] << ' ';
	}
	fs.close();
	return 0;
}