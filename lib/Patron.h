#include <iostream>

using namespace std;

namespace Patronbase {

	class Patron
	{
	public:
		Patron::Patron(string name, string id, int fee);

		string username() const { return arg_username; };
		string id() const { return arg_id; };
		int fee() const { return arg_fee; };

		void set_fee(int f) { Patron::arg_fee = f; };

		bool have_paid() { if (paid) return true; };

	private:
		string arg_username;
		string arg_id;
		int arg_fee;
		bool paid;
	};

}