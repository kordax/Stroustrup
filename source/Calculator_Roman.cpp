// Calculator_Roman.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

enum Roman I, V;

vector<string> rval;

const char roman = 'r';
const char elem = 'e';
const char integer = 'i';

class Roman_int{
public:
	char type;
	string value;
	int ivalue;

	Roman_int(char t, string v) :type(t), value(v) {};
	Roman_int(char t) :type(t) {};
	Roman_int() :type(), value() {};
};

class Roman_stream{
public:
	Roman_stream();
	Roman_int get();
	void putback(Roman_int r);
	bool is_full;
	Roman_int buffer;
};

Roman_stream::Roman_stream()
:is_full(false), buffer()    // no Token in buffer
{
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

const char quit = 'q';
const char print = '=';

double expression();

Roman_int get()
{
	char ch;
	cin >> ch;
	switch (ch) {
	case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
	case '%':
	{
		return Roman_int(ch);
	}
	case 'I': case 'V': case 'X':
	{
		cin.putback(ch);
		cin >> ch;
		return Roman_int(roman, "ch");
	}
	default:
		error("bad input");
	}
}

// deal with numbers and parentheses
double primary()
{
	Roman_int r = rs.get();
	switch (r.type) {
	case '(':    // handle '(' expression ')'
	{
					 double d = expression();
					 r = rs.get();
					 if (r.type != ')') error("')' expected");
					 return d;
	}
	case '{':    // handle '(' expression ')'
	{
					 double d = expression();
					 r = rs.get();
					 if (r.type != '}') error("'}' expected");
					 return d;
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case roman:            // we use '8' to represent a number
		return calculate_int(r);  // return the number's value
	default:
		error("primary expected");
		keep_window_open();
	}
}

//------------------------------------------------------------------------------

// deal with factorial
double factcalc()
{
	int fac1 = 1, fac2 = 1;
	double left = primary();
	Roman_int r = rs.get();

	while (true) {
		switch (r.type) {
		case '!':
		{
					if (left == 0) left = 1;
					while (fac2 < left)
					{
						fac1 = fac1*(fac2 + 1);
						fac2++;
					}
					left = fac1;
					r = rs.get();
					break;
		}
		default:
			rs.putback(r);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = primary();
	Roman_int r = rs.get();        // get the next token from token stream

	while (true) {
		switch (r.type) {
		case '*':
			left *= primary();
			r = rs.get();
			break;
		case '/':
		{
					double d = primary();
					if (d == 0) error("divide by zero");
					left /= d;
					r = rs.get();
					break;
		}
		case '%':
		{
					double d = term();
					int i1 = int(left);
					int i2 = int(d);
					return i1%i2;
		}
		default:
			rs.putback(r);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Roman_int r = rs.get();        // get the next token from token stream

	while (true) {
		switch (r.type) {
		case '+':
			left += term();    // evaluate Term and add
			r = rs.get();
			break;
		case '-':
			left += term();    // evaluate Term and subtract
			r = rs.get();
			break;
		default:
			rs.putback(r);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

int main()
try
{
	Roman_int rom;
	int romint;

	cout << "Enter your Roman int: ";
	rom = get();
	keep_window_open();
}

catch (runtime_error& e) {
	cerr << "error: " << e.what() << endl;
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}