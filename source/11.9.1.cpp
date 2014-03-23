// 11.9.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

bool is_white(const char& ch, const string& symbols)
{
	for (int i = 0; i < symbols.size(); ++i)
	{
		if (ch == symbols[i]) return true;
	}
	return false;
}

void filtr_string(string& s, const string& symbols)
{
	string res;
	for (int i = 0; i < s.size(); ++i)
	{
		if (!is_white(s[i], symbols)) res += tolower(s[i]);
	}
	s = res;
}

vector<string> split(const string& s)
{
	vector<string> temp;
	istringstream iss;

	string copy = s;
	filtr_string(copy, "',;:");
	iss.str(copy);

	string word;

	while (iss >> word)
	temp.push_back(word);

	return temp;
}

int main()
{
	vector<string> words;
	string s;
	getline(cin, s);
	words = split(s);
	return 0;
}

