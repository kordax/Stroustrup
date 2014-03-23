#include <iostream>
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

using namespace std;

namespace Librarybase
{
	struct Transaction
	{
		Bookbase::Book obj_book;
		Patronbase::Patron obj_patron;
		Chrono::Date obj_date;

		Transaction tr(Bookbase::Book obj_book, Patronbase::Patron obj_patron, Chrono::Date obj_date);
	};
	class Library
	{
	private:
		vector<Bookbase::Book> books;
		vector<Patronbase::Patron> patrons;
		vector<Transaction> transactions;
	public:

		Library::Library(vector<Patronbase::Patron> patrons, vector<Bookbase::Book> books, vector<Transaction> transactions);

		void add_transaction(Bookbase::Book bk, Patronbase::Patron pt, Chrono::Date dt)
		{
			Transaction tr;
			Transaction tr(Bookbase::Book bk, Patronbase::Patron pt, Chrono::Date dt);
			transactions.push_back(tr);
		};

		void add_book(Bookbase::Book book)
		{
			books.push_back(book);
		};

		void add_patron(Patronbase::Patron patron)
		{
			patrons.push_back(patron);
		};

	}; // Library

}