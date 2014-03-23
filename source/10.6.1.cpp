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

	Punct_stream(ifstream& is)
		:source(is) {}

	ifstream& source;
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
	if (!buffer || source.fail() || source.bad()) return false;
	else return true;
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
		if (!is_white(s[i])) res += tolower(s[i]);
	}
	s = res;
}

Punct_stream& Punct_stream::operator>>(string& s)
{
	while (!(buffer >> s)) // Если в потоке buffer есть символы, то будет выполняться инструкция buffer >> s и s получит 1 слово.
	{
		if (buffer.bad() || source.eof()) return *this;
		buffer.clear();

		string line;
		getline(source, line);

		filtr_string(line);

		buffer.str(line);
	}
	return *this;
}

ostream& operator<<(ostream& os, const vector<string>& vs)
{
	for (int i = 0; i < vs.size(); ++i)
	{
		os << i << " word: " << vs[i] << '\n';
	}
	return os;
}

void translate(string& s)
{
	if (s == "dont") s = "do not";
	if (s == "cant") s = "cannot";
	if (s == "wouldnt") s = "would not";
	if (s == "wont") s = "will not";
}

int main()
{
	vector<string> words;
	string i_name, o_name;

	i_name = "E:\input.txt";
	o_name = "E:\output.txt";

	ifstream ifs(i_name.c_str());
	if (!ifs) error("Cannot open i filestream!");
	ofstream ofs(o_name.c_str());
	if (!ofs) error("Cannot open o filestream!");

	Punct_stream ps(ifs);
	ps.set_symbols("'-");

	string str1;
	while (ps >> str1)
	{
		translate(str1);
		words.push_back(str1);
	}
	
	ofs << words;
	ofs.close();
	keep_window_open();
	return 0;
}

