// 18-2.cpp: определяет точку входа для консольного приложения.
//

#include <std_lib_facilities.h>

vector<int> gv(10);

int fac(const int& n)
{
	int r = 1;
	for (int i = 1; i <= n; ++i) r = r * i;
	return r;
}

int main()
{
	int n = 1;
	for (int i = 0; i < 10; ++i, n = n + n) gv[i] = n * 2;
	int aa[10] {1, fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10)};
	return 0;
}

