#include <iostream>
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

using namespace std;

namespace MoneyBase {

	class Money{
	public:

		Money::Money(float d, float c, string t) :dollars(d), cents(c), type(t) { };
		Money::Money() :dollars(0), cents(0), type() {};

		float cents;
		float dollars;
		long suma;
		string type;

		void rates()
		{
			//if (type == "RUB") 
			//	dollars = dollars / 32;
			//if (type == "RUB") 
			//	cents = cents * 3.088;
		}

	};

	istream& operator>>(istream& is, Money& m)
	{
		int dol;
		float cen;
		int rem;
		string type;
		char ch, ch2, ch3;
		if (!is) return is;
		do{
			is >> ch >> dol >> ch2 >> cen;
		if (cen >= 100)
		{
			cout << "Wrong input!" << '\n';
			is.clear(ios_base::failbit);
			is.clear();
		}
		} while (cen >= 100);
		if (ch != '$' && ch != 'R' || ch2 != '.' || cen > 100 || dol < 0)
		{
			error("wrong input");
			is.clear(ios_base::failbit);                    // set the fail bit
			return is;
		}
		if (ch == '$') type = "USD";
		if (ch == 'R') type = "RUB";
		m = Money(dol, cen, type);
		return is;
	}

	ostream& operator<<(ostream& os, Money& m)
	{
		m.rates();
		return os << '$' << m.dollars << '.' << m.cents;
	}

	Money operator+(Money m1, Money m2)
	{
		Money r;
		if (m1.type != m2.type)
		{
			m1.rates();
			m2.rates();
		}
		r.type = m1.type;
		r.suma = (m1.dollars * 100 + m2.dollars * 100) + (m1.cents + m2.cents);
		r.dollars = r.suma / 100;
		int temp = r.suma / 100;
		r.cents = r.suma - temp * 100; //2504
		return r;
	}

}