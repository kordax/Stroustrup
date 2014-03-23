// 11.2.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>
#include <iostream>
#include <string>
#include <sstream>

class Punct_stream
{
public:
	
	Punct_stream(istream& is)
		:source(is) {}

	void set_symbols(const string& s)
	{
		white = s;
	}

	bool is_whitespace(const char& c)
	{
		for (int i = 0; i < white.size(); ++i)
		{
			if (white[i] == c) return true;
		}
		return false;
	}

	Punct_stream& Punct_stream::operator>>(string& s);
	operator bool();

	istream& source;
	istringstream buffer;
	string white;
};

Punct_stream::operator bool()
{
	return !(source.fail() || source.bad()) && source.good();
}

Punct_stream& Punct_stream::operator>>(string& s)
{
	while (!(buffer >> s))
	{
		if (buffer.bad() || !source.good()) return *this;
		buffer.clear();

		string line;
		getline(source, line);

		for (int i = 0; i < line.size(); ++i)
		{
			if (is_whitespace(line[i]))
				line[i] = ' ';
		}
		buffer.str(line);
	}
	return *this;
}

int main()
{
	Punct_stream ps(cin);
	ps.set_symbols("aeuioy");

	string result;
	while (ps >> result) 	cout << result;
	keep_window_open();
	return 0;
}

