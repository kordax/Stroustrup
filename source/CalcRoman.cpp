// CalcRoman.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

// Классы Rom, Rom Stream и их методы

const char number = '8';

class Rom
{
public:
	string value;
	char type;
	int ival;

	Rom(char t, string v) :type(t), value(v) {};
	Rom(char t) :type(t), value() {};
	Rom(int i) :ival(i) {};
	Rom() :type(), value() {};
};

class Rom_stream
{
public:
	Rom buffer;
	bool is_full;
	void to_buffer(Rom);
	Rom get_buffer();
	Rom get();

	Rom_stream() :buffer(), is_full(false) {} ;
};

Rom_stream romstr;

void Rom_stream::to_buffer(Rom r)
{
	if (is_full) error("putback() into a full buffer");
	is_full = true;
	buffer = r;
}

Rom Rom_stream::get_buffer()
{
	is_full = false;
	return buffer;
}

//. Классы Rom, Rom Stream и их методы

// Блок обработки Римских цифр

bool is_roman(char ch)
{
	if (ch == 'X' || ch == 'I' || ch == 'V' || ch == 'M' || ch == 'C') return true;
	else return false;
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

string to_rom(int n)
{
	if (n == 1) return "I";
	if (n == 2) return "II";
	if (n == 3) return "III";
	if (n == 4) return "IV";
	if (n == 5) return "V";
	if (n == 6) return "VI";
	if (n == 7) return "VII";
	if (n == 8) return "VIII";
	if (n == 9) return "IX";
	if (n == 10) return "X";
	if (n == 11) return "XI";
	if (n == 12) return "XII";
	if (n == 13) return "XIII";
	if (n == 14) return "XIV";
	if (n == 15) return "XV";
}

int calculate_int(string val)
{
	char ch1, ch2;
	int value = 0;
	int temp;
	int roman;
	for (int i = 1; i <= val.size(); ++i)
	{
		ch2 = val[i];
		ch1 = val[i - 1];
		roman = to_int(ch1);
		if (ch2 == 'X' || ch2 == 'V' || ch2 == 'M' && ch1 == 'I') { roman *= -1; };
		value += roman;
	}
	return value;
}

//. Блок обработки Римских цифр

// Блок обработки ввода-вывода

Rom get_rom()
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
	return Rom(number, value);
};

Rom Rom_stream::get()
{
	if (is_full) { Rom rr = get_buffer(); return rr; };
	char ch;
	Rom r;
	cin >> ch;
	switch (ch)
	{
	case '(': case ')': case '=': case '+': case '-': case '*': case '/':
		return Rom(ch);
	case 'X': case 'I': case 'V': case'M': case'C':
		cin.unget();
		r = get_rom();
		r.ival = calculate_int(r.value);
		return r;
	default:
		error("wrong input");
	}
}

int expression();

int primary()
{
	Rom r = romstr.get();
	switch (r.type) {
	case '(':    // handle '(' expression ')'
	{
					 int d = expression();
					 r = romstr.get();
					 if (r.type != ')') error("')' expected");
					 return d;
	}
	case '{':    // handle '(' expression ')'
	{
					 int d = expression();
					 r = romstr.get();
					 if (r.type != '}') error("'}' expected");
					 return d;
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:            // we use '8' to represent a number
		return r.ival;// return the number's value
	default:
		error("primary expected");
		keep_window_open();
	}
	return 0;
}

int term()
{
	int left = primary();
	while (true)
	{
		Rom r = romstr.get();
		switch (r.type)
		{
		case '*':
			left = left * primary();
			break;
		case '/':
			left = left / primary();
			break;
		default:
			romstr.to_buffer(r);
			return left;
		}
	}
}

// Смысл функций expression и term сводится к тому, чтобы получить число и следующий за ним знак
// и провести операции согласно порядку их следования, т.е. сначала умножение, потом сложение.

int expression()
{	// 13 + 5 * 2
	int left = term(); // Сначала мы получаем левое значение, проверяя все функции.
	while (true) // Цикл while работает до тех пор, пока в get есть поток;
	{
		Rom r = romstr.get(); // Потом мы считываем следующий символ, тоже самое в функции term. Если это + или *, то работает соотв. функция
		switch (r.type)
		{
		case '+':
			left = left + term(); // После этого, мы производим операции и получаем правое число.
			break;
		case '-':
			left = left - term();
			break;
		default:
			romstr.to_buffer(r); // Функция не обрабатывала этот символ, поэтому поместим его в буфер, чтобы считать при следующем вызове функции romstr.get
			return left;
		}
	}
}
// 13+5*2=
//. Блок обработки ввода-вывода

int main()
try
{
	Rom r;
	int intres;
	string romres;
	cout << '>';
	intres = expression();
	//romres = to_rom(intres);
	cout << intres;
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

