
//
// This is example code from Chapter 17.2 "Vector basics" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <std_lib_facilities.h>

//------------------------------------------------------------------------------

namespace Vec
{
	class vector {
		int sz;                   // the size
		double* elem;             // pointer to the first element (of type double)
	public:
		vector(int s) : sz(s), elem(new double[s]) { for (int i = 0; i < s; ++i) elem[i] = 0; }
		~vector(){ delete[] elem; }

		int size() const { return sz; } // the current size

		double get(int n) { return elem[n]; }
		void set(int n, double v) { elem[n] = v; }
	};
}

class A {
public:
	int date;

	A() { cout << "A()" << endl; }
	virtual ~A() { cout << "~A()" << endl; }
};

class B : public A
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
};

// Link

class Link {
public:
	string value;

	Link(const string& v, Link* p = 0, Link* s = 0)
		: value(v), prev(p), succ(s) { }

	Link* insert(Link* n);   // insert n before this object
	Link* add(Link* n);      // insert n after this object
	Link* erase();           // remove this object from list
	Link* find(const string& s);    // find s in list
	const Link* find(const string& s) const; // find s in list

	Link* advance(int n) const;     // move n positions in list

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};

//------------------------------------------------------------------------------

Link* Link::insert(Link* n)   // insert n before this object; return n
{
	if (n == 0) return this;
	if (this == 0) return n;
	n->succ = this;           // this object comes after n
	if (prev) prev->succ = n;
	n->prev = prev;           // this object's predecessor becomes n's predecessor
	prev = n;                 // n becomes this object's predecessor
	return n;
}

void print_array(ostream& os, vector<int> *a)
{
	int res;
	for (int i = 0; i < 10; ++i)
	{
		os << a;
	}
}

int main()
{
	Link* norse_gods = new Link("Thor");
	norse_gods = norse_gods -> insert(new Link("Odin"));
	norse_gods = norse_gods->insert(new Link("Odin"));
	norse_gods = norse_gods->insert(new Link("Odin"));

	delete[] norse_gods;

	vector<int> *massive = new vector<int>[10];

	print_array(cout, massive);
	delete[] massive;
	keep_window_open();
}