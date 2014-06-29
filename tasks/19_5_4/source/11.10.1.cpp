// 11.10.1.cpp: определяет точку входа для консольного приложения.
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

vector<string> split(const string& s, const string& symbols)
{
	vector<string> temp;
	istringstream iss;

	string copy = s;
	filtr_string(copy, symbols);
	iss.str(copy);

	string word;

	while (iss >> word)
		temp.push_back(word);

	return temp;
}

/*

vector<int> spliti(const string& s)
// return a vector of indices of words in s
{
	vector<int> res;
	bool in_word = false;
	for (int i = 0; i<s.size(); ++i) {
		if (isspace(s[i]))
			in_word = false;
		else {
			if (!in_word)	// first character in word
				res.push_back(i);
			in_word = true;
		}
	}
	return res;
}

void print_word1(const string& s, int i)
// print whitespace terminated word
// the last word in the string is *not* whitespace terminated; we stop at the end of string
{
for (int i = 0; i<s.size() && !isspace(s[i]); ++i)
cout << s[i];
cout << ' ';
}

*/


int main()
{
	vector<string> words;
	string s;
	getline(cin, s);
	words = split(s, "!,';:.");
	return 0;
}

