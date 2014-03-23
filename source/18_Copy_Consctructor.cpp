
//
// This is example code from Chapter 18.3.1 "Debugging constructors and destructors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <std_lib_facilities.h>

//------------------------------------------------------------------------------

struct X {    // simple test class
	int val;

	void out(const string& s)
	{
		cerr << this << "->" << s << ": " << val << "\n";
	}

	X(){ out("call: default constructor X()"); val = 0; }
	X(int v) { out("call: constructor X(int)"); val = v; }
	X(const X& x){ out("call: copy constructor X(X&) "); val = x.val; }
	X& operator=(const X& a) { out("X::operator=()"); val = a.val; return *this; }
	~X() { out("~X()"); }
};

//------------------------------------------------------------------------------

X glob(2);            // a global variable

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

//------------------------------------------------------------------------------

namespace vec
{

	class vector {
		int sz;          // the size
		double* elem;    // a pointer to the elements
	public:
		vector(int s) :sz(s), elem(new double[s]) { } // constructor
		~vector() { delete[] elem; }                  // destructor
		// ...
		const double operator[](int n) const { return elem[n]; } // const return element
		double& operator[](int n) { return elem[n]; }  // return element
	};
}

int main()
{
	int* p = new(int);
	int* c = new(int);
	cout << p << ' ' << *p << '\n';
	*p = *c;
	cout << p << ' ' << *p << '\n';
}

//------------------------------------------------------------------------------
