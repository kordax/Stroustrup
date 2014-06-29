#include "stdafx.h"

// CalculatorWin.cpp: определяет точку входа для консольного приложения.
//

#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>
#include "filemode.h"


/*
calculator08buggy.cpp

Helpful comments removed.

We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char from = 'f';

bool file_mode = false;
bool input_file_known = false;

struct Token {
	char kind;
	double value;
	string name;
	Token() {};
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) {}
};

class Token_stream {
private:
	bool full;
	Token buffer;
public:
	Token_stream();
	Token fmode_get(istream& is);
	Token get();
	void unget(Token t);
	void ignore(char);
};

void Token_stream::unget(Token t) { buffer = t; full = true; }

void filework();

istream& operator>>(istream& is, Token t)
{
	char ch;
	is >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		t.kind = ch;
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		{
				is.unget();
				double val;
				is >> val;
				t.kind = number;
				t.value = val;
		}
	}
	return is;
}

Token_stream::Token_stream()
:full(false), buffer(0) { }

Token Token_stream::get()
{
	if (full) { full = false; return buffer; };
	char ch;
	if (file_mode && !input_file_known) // Получаем название входного файла
	{
		Token t;
		string filename;
		cin >> filename;
		t.name = filename;
		return t;
	}
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
				cin.unget();
				double val;
				cin >> val;
				return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			if (s == "from") return Token(from);
			if (s == "let") return Token(let);
			if (s == "quit") return Token(quit);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
	if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
	if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
	if (names[i].name == s) {
		names[i].value = d;
		return;
	}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
	if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

Token Token_stream::fmode_get(istream& is)
{
	if (full) { full = false; return buffer; };
	if (input_file_known) //Если файл известен, производим вычисления
	{
		char ch;
		is >> ch;
		switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
			return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
					is.unget();
					double val;
					is >> val;
					return Token(number, val);
		}
		default:
			if (isalpha(ch)) {
				string s;
				s += ch;
				while (is.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				is.unget();
				if (s == "from") return Token(from);
				if (s == "let") return Token(let);
				if (s == "quit") return Token(quit);
				return Token(name, s);
			}
			error("Bad token");
		}
	}
}

//=РАБОТА=С=ФАЙЛОМ===============================================================

double f_expression(istream& is);

double f_primary(istream& is)
{
	Token t = ts.fmode_get(is);
	switch (t.kind) {
	case '(':
	{	double d = f_expression(is);
	t = ts.fmode_get(is);
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -f_primary(is);
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double f_term(istream& is)
{
	double left = f_primary(is);
	while (true) {
		Token t = ts.fmode_get(is);
		switch (t.kind) {
		case '*':
			left *= f_primary(is);
			break;
		case '/':
		{	double d = f_primary(is);
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double f_expression(istream& is)
{
	double left = f_term(is);
	while (true) {
		Token t = ts.fmode_get(is);
		switch (t.kind) {
		case '+':
			left += f_term(is);
			break;
		case '-':
			left -= f_term(is);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

///=РАБОТА=С=ФАЙЛОМ===============================================================

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}


void filework()
{
	file_mode = true;
	Token t = ts.get(); // Получаем путь файла, записываем его в поле Token t - name: "E:\input.txt";
	string output_file;
	cout << "Input file path: ";
	cout << t.name;
	cout << '\n';
	ifstream is(t.name.c_str());
	cout << "Enter output file: ";
	cin >> output_file;
	ofstream os(output_file.c_str());
	if (!is) error("Cannot open input stream");
	input_file_known = true;
	if (!os) error("Cannot open output stream");

	double d = f_expression(is);
	string str, result;
	is.seekg(0);
	while (is)
	{
		is >> str;
		if (is) result += str;
	}
	os << result << d;
	return;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		if (t.kind == from)
		{
			filework();
			return;
		}
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c&& c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
