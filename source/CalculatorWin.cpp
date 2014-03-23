#include "stdafx.h"

// CalculatorWin.cpp: определяет точку входа для консольного приложения.
//

#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

const char number = '8';
const char quit = 'q';
const char print = '=';
const string promt = "> ";
const string result = "= ";

//------------------------------------------------------------------------------

class Name_value {
public:
	Name_value();
	string name_str;
	double name_val;
	Name_value(string str, double val2)
		:name_str(str), name_val(val2){}
};

//------------------------------------------------------------------------------

// Name_value constructor
Name_value::Name_value()
{
}

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
	void ignore(char c);
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// Variable class:

class Variable {
public:
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) {}
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{

	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case print:    // for "print"
	case quit:    // for "quit"
	case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
	case '%':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);         // put digit back into the input stream
			double val;
			cin >> val;              // read a floating-point number
			return Token(number, val);   // let '8' represent "a number"
			  }
	default:
		error("bad token");
		keep_window_open();
	}
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// Clean up mess function:
void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

// Ignore function:

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind){
		full = false;
		return;
	}
	full = false;
	char ch = 0;
	while (cin >> ch)
	if (ch == c) return;
}

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
				return d;
				 }
	case '{':    // handle '(' expression ')'
		{
			double d = expression();
			t = ts.get();
			if (t.kind != '}') error("'}' expected");
			return d;
				 }
	case '-':
		return - primary();
	case '+':
		return primary();
	case number:            // we use '8' to represent a number
		return t.value;  // return the number's value
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
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '!':
			{
				if (left == 0) left = 1;
				while (fac2 < left)
				{
					fac1 = fac1*(fac2 + 1);
					fac2++;
				}
				left = fac1;
				t = ts.get();
				break;
				}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
			{
				double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				t = ts.get();
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
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left += term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

void calculate()
try
{
	double val = 0;
	while (cin) {
		cout << promt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << expression() << endl;
	}
}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		clean_up_mess();
	}

int main()
try
{
	calculate();
	keep_window_open();
	return 0;
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

//------------------------------------------------------------------------------
