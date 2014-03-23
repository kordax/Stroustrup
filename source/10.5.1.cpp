// 10.5.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>
#include <iostream>
#include <string>
#include <sstream>

class Punct_stream
{
public:

	Punct_stream(istream& cins)
		:source(cins) {}

	istream& source;
	istringstream buffer;
	string symbols;
	operator bool();
	void Punct_stream::filtr_string(string& s);

	void set_symbols(const string& s);
	bool is_white(const char& ch);
	Punct_stream& operator>>(string& s);

};

void Punct_stream::set_symbols(const string& s)
{
	symbols = s;
}

Punct_stream::operator bool()
{
	return !(source.fail() || source.bad()) && source.good();
}

bool Punct_stream::is_white(const char& ch)
{
	for (int i = 0; i < symbols.size(); ++i)
	{
		if (ch == symbols[i]) return true;
	}
	return false;
}

void Punct_stream::filtr_string(string& s)
{
	string res;
	for (int i = 0; i < s.size(); ++i)
	{
		if (!is_white(s[i])) res += s[i];
	}
	s = res;
}

Punct_stream& Punct_stream::operator>>(string& s)
{
	while (!(buffer >> s)) // Если в потоке buffer есть символы, то будет выполняться инструкция buffer >> s и s получит 1 слово.
	{
		if (buffer.bad() && !source.good()) return *this;
		buffer.clear();

		string line;
		getline(source, line);

		filtr_string(line);

		buffer.str(line);
	}
	return *this;
}

int main()
{
	Punct_stream ps(cin);
	ps.set_symbols("'-");

	string str1;
	while (ps >> str1) cout << str1 << ' ';
	keep_window_open(0);
	return 0;
}

