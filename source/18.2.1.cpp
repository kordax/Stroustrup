// 18.2.1.cpp: определяет точку входа для консольного приложения.
//

#include <std_lib_facilities.h>

char* str_dup(const char* ch)
{
	if (!ch) return NULL;
	int len = 0;

	while (*ch) { ch++; len++; }
	ch -= len; // Переходим в начало строки

	char* dup = new char[len];

	while (*ch)
	{
		*dup = *ch;
		ch++;
		dup++;
	}

	*dup = 0; // Признак конца строки
	dup -= len;
	return dup;
}

char* findx(const char* s, const char* x)
{
	char *sc;
	char *xc;
	xc = str_dup(x);
	sc = str_dup(s);
	int cnt = 0;
	while (*xc && *sc) //12345673578 & 357
	{
		if (*xc == *sc)
		{
			++sc;
			++xc;
			++cnt;
		}
		else
		{
			++sc;
			xc = str_dup(x);
			cnt = 0;
		}
	}

	if (*xc) { return 0; }

	xc -= cnt;
	return xc;
}

int str_cmp(const char* s1, const char* s2)
{

}

int main()
{

	return 0;
}

