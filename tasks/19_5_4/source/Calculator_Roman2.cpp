// Calculator_Roman2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

class Roman_int{
public:
	char type;
	string value;
	int ivalue;

	Roman_int(char t, string v, int ival) :type(t), value(v), ivalue(ival) {};
	Roman_int(char t, string v) :type(t), value(v) {};
	Roman_int(char t) :type(t) {};
	Roman_int(string v) :value(v) {};
	Roman_int() :type(), value(), ivalue() {};
};

class Roman_stream{
public:
	Roman_stream();
	Roman_int get();
	void unget(Roman_int r);
	void putback(Roman_int r);
	bool is_full;
	Roman_int buffer;
};

Roman_stream::Roman_stream()
:is_full(false), buffer()    // no Token in buffer
{
}

void Roman_stream::unget(Roman_int r)
{
	is_full = true;
	buffer = r;
}

Roman_stream rs;


bool is_roman(char ch)
{
	if (ch == 'X' || ch == 'I' || ch == 'V' || ch == 'M') return true;
	else return false;
}

bool check_roman(const Roman_int &r)
{
	char ch1, ch2, ch3, ch4;
	for (int i = 2; i <= r.value.size(); ++i)
	{
		ch3 = r.value[i];
		ch2 = r.value[i - 1];
		ch1 = r.value[i - 2];
		if (ch1 == 'I' && ch2 == 'I' && ch3 == 'X' || ch3 == 'V' || ch3 == 'M') return false;
	}
	return true;
}

int to_int(char ch)
{
	if (ch == 'I') return 1;
	if (ch == 'V') return 5;
	if (ch == 'X') return 10;
	if (ch == 'C') return 100;
	else
	{
		error("not Roman int");
		return 0;
	}
}

int calculate_int(Roman_int r)
{
	char ch1, ch2;
	int value = 0;
	int temp;
	int rom;
	for (int i = 1; i <= r.value.size(); ++i)
	{
		ch2 = r.value[i];
		ch1 = r.value[i - 1];
		rom = to_int(ch1);
		if (ch2 == 'X' || ch2 == 'V' || ch2 == 'M' && ch1 == 'I') { rom *= -1; };
		value += rom;
	}
	return value;
}

istream& operator>>(istream& is, Roman_int &r)
{
	string value;
	string input;
	char ch;
	is >> input;
	for (int i = 0; i < input.size(); ++i)
	{
		ch = input[i];
		if (is_roman(ch))
		{
			value += ch;
			r.value = value;
		}
	}
	if (!check_roman(r)) error("Wrong Roman input!");
	r.ivalue = calculate_int(r);
	return is;
}

ostream& operator<<(ostream& os, Roman_int r)
{
	os << r.value;
	return os;
}

Roman_int par()
{
	return Roman_int();
}

int expression()
{
	char ch;
	Roman_int r = rs.get();
	int value = calculate_int(r);
	switch (r.type)
	{
	case '+':
		value += expression();
		return value;
	case '-':
		value -= expression();
		return value;
	default:
		rs.unget(r);
		return value;
	}
}

Roman_int getrom()
{
	char ch;
	string value;
	cin >> ch;
	while (is_roman(ch))
	{
		value += ch;
		cin >> ch;
	}
	cin.unget();
	return Roman_int(value);
}

Roman_int Roman_stream::get()
{
	Roman_int r;
	string value;
	char ch;
	cin >> ch;
	switch (ch){
	case '(': case ')': case '=': case '+': case '-':
		return Roman_int(ch);
	case 'X': case 'I': case 'V': case'M': case'C':
		value += ch;
		cin.unget();
		r = getrom();
		return r;
	default:
		error("wrong input");
	}
}

Roman_int start()
{
	char ch;
	string value;
	Roman_stream rs;
	Roman_int r;
	cin >> ch;
	cin.unget();
	r = rs.get();
	return r;
}

int main()
{
	char ch;
	Roman_int r;
	r = start();
	cout << expression();
	keep_window_open();
	return 0;
}

