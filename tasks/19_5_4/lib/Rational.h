#include <iostream>
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

using namespace std;

/*	Design decisions:
1. allow direct access to the representation(num, den)
2. try to keep rational numbers "normalized", that is with the smallest possible denominator
(e.g. 5 / 3 rather than 15 / 9); that requires a gcd(greatest common denominator) function.
3. don't try to make the code very fast; "simple and not too inefficient" is the ideal (to keep the code simple)
4. I won't check for overflow (to keep the code simple)
*/

namespace Ratbase {
	
	int gcd(int x, int y)
		// greatest common denominator
		// Euclid's algorithm (using remainder)
	{
		x = abs(x);	// don't get confused by negative values
		y = abs(y); // 14/6 gcd = 2 || 15/9 gcd = 3
		while (y) {
			int t = y;
			y = x%y;
			x = t;
		}
		return x;
	}

	class Rational
	{
	public:
		Rational(int n, int d) :num(n), den(d) { normalize(); }
		// Rational(int n) :num(n), den(1) { }	// deleted because I kept writing things like Rational(24/8)
		Rational() :num(0), den(1) { }

		void normalize()	// keep denominator positive and minimal
		{
			if (den == 0) error("0 denominator");
			if (den<0) { den = -den; num = -num; }
			int n = gcd(num, den);
			if (n>1) { num /= n; den /= n; } // 14/6 - 14/gcd, 6/gcd = 7/3
		}

		int num, den;
	};

	ostream& operator<<(ostream& os, Rational x)
	{
		return cout << '(' << x.num << '/' << x.den << ')';
	}

	bool operator==(Rational x1, Rational x2)
	{
		return x1.num*x2.den == x1.den*x2.num;
	}

	bool operator!=(Rational x1, Rational x2)
	{
		return !(x1 == x2);
	}

	double to_double(Rational x)	// convert to double (to floating point representation)
	{
		return double(x.num) / x.den;
	}

	//----- arithmetic operations --------------------------------------------------------

	Rational operator+(Rational x1, Rational x2)
	{
		Rational r(x1.num*x2.den + x1.den*x2.num, x1.den*x2.den);
		r.normalize();
		return r;
	}

	Rational operator-(Rational x1, Rational x2)
	{
		Rational r(x1.num*x2.den - x1.den*x2.num, x1.den*x2.den);
		r.normalize();
		return r;
	}

	Rational operator-(Rational x)	// unary minus
	{
		return Rational(-x.num, x.den);
	}

	Rational operator*(Rational x1, Rational x2)
	{
		Rational r(x1.num*x2.num, x1.den*x2.den);
		r.normalize();
		return r;
	}

	Rational operator/(Rational x1, Rational x2)
	{
		Rational r(x1.num*x2.den, x1.den*x2.num);
		r.normalize();
		return r;
	}


}