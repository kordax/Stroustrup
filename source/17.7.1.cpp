// 17.7.1.cpp: определяет точку входа для консольного приложения.
//

#include <std_lib_facilities.h>

//------------------------------------------------------------------------------

int str_len(const char* s)
{
	const int MAXLEN = 512; // max allowable string length
	int len = 0; // calculated length of string, 0 == error (null str, not null terminated, too long)
	if (*s){
		for (int i = 0; i<MAXLEN; ++i)
		if (s[i])
			++len;
		else
			break; // end of string s
	}

	if (len == MAXLEN)
	if (s[MAXLEN])
		len = 0; // string too long and not null terminated

	return len;
}

void make_c_str(char * s, int len)
{
	s += len;
	*s = 0;
	s -= len;
}

char* str_dup(const char *s)
{
	int counter = 0;
	int len = str_len(s);
	char *str = new char[len];
	make_c_str(str, len);
	while (*s != 0)
	{
		*str = *s;
		++s;
		++str;
		++counter;
	}
	str -= counter;
	s -= counter;
	return str;
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

//==============================================================================

int main()
{
	int mem_size = 5;
	char *ch = new char;
	string str;
	while (true)
	{
		if (!*ch)
		{
			realloc(ch, mem_size + 1);
			--ch;
		}
		*ch = cin.get();
		str.push_back(*ch);
		++ch;
		if (*ch == '!') break;
	}
	keep_window_open();
}