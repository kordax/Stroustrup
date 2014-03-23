// 10.4.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

void analyze_str(const string& s)
{
	char ch, ch2;
	for (int i = 0; i < s.size(); ++i)
	{
		ch = s[i];
		if (isspace(ch)) cout << setw(1) << ch << setw(15) << " is space ";
		if (isalpha(ch)) cout << setw(1) << ch << setw(15) << " is alpha ";
		if (isdigit(ch)) cout << setw(1) << ch << setw(15) << " is digit;" << '\n';
		if (islower(ch)) cout << setw(1) << setw(15) << "in lower register;" << '\n';
		if (ispunct(ch)) cout << setw(1) << ch << setw(15) << "is punct;" << '\n';
		if (isupper(ch)) cout << setw(1) << setw(15) << "in upper register;" << '\n';
	}
		
}

int main()
{
	string str;
	cin >> str;
	analyze_str(str);
	keep_window_open();
	return 0;
}

