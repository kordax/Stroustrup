// 18.1.1.cpp: определяет точку входа для консольного приложения.
//

#include <std_lib_facilities.h>

char* strdup(const char* ch)
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

int main()
{
	char ch[] = "govnoebanoe";
	cout << strdup(ch);
	return 0;
}

