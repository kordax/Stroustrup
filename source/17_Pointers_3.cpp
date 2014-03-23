
#include <std_lib_facilities.h>

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
	Link* previous() { return prev; }
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

/*
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
*/

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



int main()
{
	Link* norse_gods = new Link("Thor", "Scandinavian", "Sleipnir", "Hummer");
	norse_gods = norse_gods->add(new Link("Bobin Acrobat", "test", "test", "test"));
	Link* p1 = new Link();
	Link* p2 = new Link();
	Link* buf = new Link();
	p1 = norse_gods->previous();
	p2 = norse_gods;

	*p1++;
}