#include <iostream>

using namespace std;

namespace Bookbase {

	class Book {
	public:
		class Invalid{};

		enum Genre{
			Drama = 1, Comedy, Tragedy, Romance, Documentary, Default
		};

		Book(string arg_isbn, string arg_name, string arg_author, Chrono::Date arg_date, bool arg_bool, Genre arg_genre);
		Book();

		// non mod functions:

		string isbn() const { return arg_isbn; };
		string name() const { return arg_name; };
		string author() const { return arg_author; };
		Genre genre() const { return arg_genre; }
		Chrono::Date date() const { return arg_date; };
		bool status() const { return arg_bool; };

		//

	private:
		string arg_isbn;
		string arg_name;
		string arg_author;
		Genre arg_genre;
		Chrono::Date arg_date;
		bool arg_bool;
	};

	//========================================================

	bool check_isbn(const string arg_isbn)
	{
		char ch;
		int counter = 0;
		for (int i = 0; i < arg_isbn.length(); ++i)
		{
			ch = arg_isbn[i];
			if (i > 5 && counter < 1) return false; //Если введено больше 5ти элементоа, а '-' не последовало
			if (!isdigit(ch) && isalpha(ch) && counter < 3) return false; // Если первые 3 элемента - буквы
			if (!isdigit(ch) && !isalpha(ch) && counter == 3) return false; // Если последний элемент не буква и не цифра
			if (counter == 3 && arg_isbn[i + 1] != false) return false; // Если последний элемент содержит больше одного символа
			if (counter > 3) return false; // Если элементов больше чем возможно
			if (ch == '-') ++counter; // Счётчик '-'
		}
		return true;
	}; // check_ISBN

	//========================================================

	bool check_name(string arg_isbn)
	{
		char ch;
		int counter = 0;
		for (int i = 0; i < arg_isbn.length(); ++i)
		{
			ch = arg_isbn[i];
			if (isdigit(ch)) return false;
		}
		return true;
	}; // check_name

	//========================================================

	//------------------------------------------------------------------------------

	ostream& operator<<(ostream& os, const Book& b)
	{
		return os << "ISBN: " << b.isbn()
			<< ',' << " Name: " << b.name()
			<< ',' << " Author: " << b.author()
			<< ',' << " Genre: " << b.genre();
	}

	istream& operator>>(istream& is, Book& dd);

	bool operator==(const Book& b, const Book& bb)
	{
		if (b.isbn() == bb.isbn()) return true;
		else return false;
	};

	bool operator!=(const Book& b, const Book& bb)
	{
		if (b.isbn() != bb.isbn()) return true;
		else return false;
	};

	//------------------------------------------------------------------------------

		Book::Book(string ISBN, string name, string author, Chrono::Date date, bool status, Genre gen)
			:arg_isbn(ISBN), arg_name(name), arg_author(author), arg_date(date), arg_bool(status), arg_genre(gen)
		{
			if (!Bookbase::check_isbn(ISBN)) throw Invalid();
		};

		const Book& default()
		{
			Chrono::Date def_date(1234, Chrono::Date::jan, 1);
			static const Book bb("default", "default", "default", def_date, false, Book::Genre::Default);
			return bb;
		};

		Book::Book()
			:arg_isbn(default().arg_isbn),
			arg_author(default().arg_author),
			arg_name(default().arg_name),
			arg_bool(default().arg_bool),
			arg_date(default().arg_date)
		{};

} // Bookbase