// 10.12.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>


int main()
{
	string name, value;
	cin >> name;
	ifstream is(name.c_str());
	int cnt = 1;
	while (is)
	{
		getline(is, value);
		if (is) cout << cnt << value << '\n';
		++cnt;
	}
	keep_window_open();
	return 0;
}

