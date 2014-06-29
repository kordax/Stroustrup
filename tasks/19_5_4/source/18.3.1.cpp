// 18.3.1.cpp: определяет точку входа для консольного приложения.
//

#include <std_lib_facilities.h>

int str_cmp(const char* s1, const char* s2)
{
	int len1, len2, len;
	while (*s1) { s1++; len1++; }
	while (*s2) { s2++; len2++; }
	s1 -= len1;
	s2 -= len2;

	while (*s1 && *s2)
	{
		if (*s1 == *s2) s1++; s2++;
	}

	return *s1 - *s2;
}

int main()
{
	return 0;
}

