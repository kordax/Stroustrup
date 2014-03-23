// 18-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <std_lib_facilities.h>

int ga[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int g[], int max)
{
	int la[10];

	for (int i = 0; i < max; ++i)
	{
		la[i] = g[i];
		cout << "la[" << i << "] = " << la[i] << '\n';
	}

	int* p = new (int [max]);
	int cnt = 0;
	
	for (int i = 0; i < max; ++i)
	{
		*p = g[i];
		cout << "*p[" << i << "] = " << *p << '\n';
		p++;
		cnt++;
	}

	p -= cnt;

	delete p;
}

int fac(const int& n)
{
	int r = 1;
	for (int i = 1; i <= n; ++i) r = r * i;
	return r;
}

int _tmain(int argc, _TCHAR* argv[])
{
	f(ga, 10);
	int aa[10] {1, fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10)};
	f(aa, 10);
	return 0;
}

