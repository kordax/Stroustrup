
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

struct God {

	God(const string &n, const string &m, const string &t, const string &w)
		: name(n), mythology(m), transport(t), weapon(w) {}

	God()
		: name("default"), transport("default"), weapon("default"), mythology("default") {}
	
	string name;
	string transport;
	string weapon;
	string mythology;
};

class Link {
public:
	int value;
	God god;

	Link(const string &n, const string &m, const string &t, const string &w, Link* p = 0, Link* s = 0)
		: god(n, m, t, w), prev(p), succ(s) { }

	Link(Link* p = 0, Link* s = 0) { };

	Link* insert(Link* n);   // insert n before this object
	Link* add(Link* n);      // insert n after this object
	Link* erase();           // remove this object from list
	Link* find(const string& s);    // find s in list
	const Link* find(const string& s) const; // find s in list

	void next();
	void previous();
	Link* to_first();
	Link* to_last();

	void set_name(const string &s) { god.name = s; }
	void set_weapon(const string &s) { god.weapon = s; }
	void set_transport(const string &s) { god.transport = s; }
	void set_mythology(const string &s) { god.mythology = s; }

	Link* add_ordered(Link* p);
	Link* advance(int n);
	void swap(Link* p1, Link* p2);
	void sort();

	void print_all();
private:
	Link* prev;
	Link* succ;
};

Link* Link::to_first()
{
	if (prev == 0) return this;
	Link* p = new Link();
	*p = *this;
	while (p->prev)
	{ 
		*p = *p->prev;
	} 
	return p;
}


Link* Link::to_last()
{
	while (this->succ) 
	{ 
		*this = *this->succ;
	} 
	return this;
}

Link* Link::find(const string& s)
{
	Link* p = this;

	p = p->to_first();

	while (p)
	{
		if (p->god.name == s) return p;
		p = p->succ;
	}

	error("Cannot find link");
	return 0;
}

/*Link* Link::swap(const string& s1, const string& s2)
{
	Link* l1;
	Link* l2;
	Link* buffer;

	l1 = find(s1);
	l2 = find(s2);

	buffer = l1; // Непосредственная операция копирования
	l1 = l2;
	l2 = buffer;

	if (l1->prev && l2->prev) // Обработчик Prev
	{
		buffer = l1->prev;
		l1->prev = l2->prev;
		l2->prev = buffer;
	}
	if (l1->succ && l2->succ) // Обработчик Succ
	{
		buffer = l1->succ;
		l1->succ = l2->succ;
		l2->succ = buffer;
	}
}*/

Link* Link::add(Link* n) //insert n after this object
{
	if (n == 0) return this;
	if (this == 0) return n;

	if (succ) succ->prev = n;
	n->succ = succ;
	n->prev = this;

	succ = n;
	return n;
}

Link* Link::advance(int n) //Заменю перегрузкой оператороа
{
	Link *p;
	*p = this;

	if (p == 0) return 0;

	if (n > 0) while (n++)
	{
		if (prev = 0) return this;
		p++;
	}
	if (n < 0) while (n++)
	{
		if (prev = 0) return this;
		p--;
	}

	return p;
}

Link* Link::add_ordered(Link* n)
{
	if (n == 0) return this;
	if (this == 0) return n;

	int i = 0;
	int i2 = 0;
}

void Link::swap(Link* p1, Link* p2)
{
	Link* buf;

	if (p1->succ == p2 || p1->prev == p2) { p1->prev = p2->prev; p1->succ = p2->succ; buf = p1; p1 = p2; p2 = buf; return; }

	if (p1->prev && p2->prev) // Обработчик Prev
	{
		buf = p1->prev;
		p1->prev = p2->prev;
		p2->prev = buf;
	}
	if (p1->succ && p2->succ) // Обработчик Succ
	{
		buf = p1->succ;
		p1->succ = p2->succ;
		p2->succ = buf;
	}

	buf = p1;
	p1 = p2;
	p2 = buf;
}

void Link::sort()
{
	*this = *this->to_first();

	Link* p = new Link();
	Link* next = new Link();
	*p = *this;

	while (true)
	{
		if (succ == 0) break;
		*next = *this->succ;
		while (true)
		{
			if (p->succ == 0) break;
			*p = *p->succ;
			if (p->god.name < this->god.name) { this->swap(p, this); break; }
		}
		if (succ == 0) break;
		*this = *this->succ;
	}

}

void Link::print_all()
{
	*this = *this->to_first();
	while (true)
	{
		int n = 1;
		cout << "#" << n;
		cout << "Name: " << god.name << '\n';
		cout << "Weapon: " << god.weapon << '\n';
		cout << "Transport: " << god.transport << '\n';
		cout << "Mythology: " << god.mythology << '\n' << '\n';
		n++;
		if (!succ) { *this = *this->to_first(); return; }
		*this = *this->succ;
	}
}

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

Link* Link::erase()
{
	if (this == 0) return this;

	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
	return succ;
}

void print_array(ostream& os, vector<int> *a)
{
	for (int i = 0; i < 10; ++i)
	{
		os << a;
	}
}

// solution #2, using pointer dereferencing:
void to_lower(char* p)
// assume that lower and upper case characters have consecutive integer values
{
	if (p == 0) return;	// just in case some user tries to_lower(0)
	for (; *p; ++p) {			// p is already initialized, so we don't need and initializer part of the for-statement
		if ('A' <= *p && *p <= 'Z') // is upper case (only characters are considered upper case - e.g. not !@#$)
			*p = *p - ('A' - 'a');	// make lower case
	}
}

void test(const string& ss)	// rely on visual inspection
{
	string s = ss;	// take a copy to avoid modifying original
	cout << s << '\n';
	char* p = &s[0];	// assume (correctly) that the characters are stored with a terminating 0
	to_lower(p);
	cout << p << '\n';
}

int str_len(const char* s)
{
	const int MAXLEN = 512; // max allowable string length
	int len = 0; // calculated length of string, 0 == error (null str, not null terminated, too long)
	if (*s){
		for (int i = 0; i<MAXLEN; ++i)
		if (s[i])
			++len;
		else
			break; // end of string s
	}

	if (len == MAXLEN)
	if (s[MAXLEN])
		len = 0; // string too long and not null terminated

	return len;
}

void make_c_str(char * s, int len)
{
	s += len;
	*s = 0;
	s -= len;
}

char* str_dup(const char *s)
{
	int counter = 0;
	int len = str_len(s);
	char *str = new char[len];
	make_c_str(str, len);
	while (*s != 0)
	{
		*str = *s;
		++s;
		++str;
		++counter;
	}
	str -= counter;
	s -= counter;
	return str;
}

char* findx(const char* s, const char* x)
{
	char *sc;
	char *xc;
	xc = str_dup(x);
	sc = str_dup(s);
	int cnt = 0;
	while (*xc && *sc) //12345673578 & 357
	{
		if (*xc == *sc)
		{
			++sc;
			++xc;
			++cnt;
		}
		else
		{
			++sc;
			xc = str_dup(x);
			cnt = 0;
		}
	}

	if (*xc) { return 0; }

	xc -= cnt;
	return xc;
}

int main()
{
	Link* norse_gods = new Link("Thor", "Scandinavian", "Sleipnir", "Hummer");
	norse_gods = norse_gods->insert(new Link("Odin", "Scandinavian", "Skibladnir", "Gungner"));
	norse_gods = norse_gods->add(new Link("Bobin Acrobat", "test", "test", "test"));
	Link* greek_gods = new Link("Zeus", "Greek", "default", "Thunder");
	greek_gods = greek_gods->insert(new Link("Poseidon", "Greek", "default", "Trizubec epta"));

	norse_gods = norse_gods->to_first();
	norse_gods->print_all();
	norse_gods->sort();
	norse_gods->print_all();
}