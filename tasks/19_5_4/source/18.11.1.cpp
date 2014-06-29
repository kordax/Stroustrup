#include <std_lib_facilities.h>

//===================================================================================================================

class Link {
public:
	int value;
	int level;
	int system_levels = 4;

	Link(int v, int l, Link* p = 0, Link* s = 0, Link* lo = 0, Link* up = 0 )
		: value(v), prev(p), succ(s), lower(lo), upper(up), level(l) { }

	Link(Link* p = 0, Link* s = 0, Link* lo = 0, Link* up = 0)
		: prev(p), succ(s), lower(lo), upper(up) { }

	Link* insert(Link* n);   // insert n before this object
	Link* insertlevel(Link* n);
	Link* Link::add(Link* n);  // Добавляем элемент с таким-же значением, слоем выше.
	Link* erase();           // remove this object from list
	Link* find(Link* n);     // find s in list
	Link* find_value_of(Link *n);
	Link* generate();

	void next();
	Link* previous() { return prev; }
	Link* to_first();
	Link* Link::to_first_elem();
	Link* to_last();

	Link* add_ordered(Link* p);
	Link* advance(int n);
	Link* Link::fill_level(Link* sys, int l);

	void swap(Link* p1, Link* p2);
	void sort();

	void print_all();
private:
	Link* prev;
	Link* succ;
	Link* upper;
	Link* lower;
	Link* base;

	int system_length = 10;
};

bool make_decision(int n)
{
	if (n > 100 || n < 1) error("Wrong percentage");
	int t = randint(1, 100);
	if (t <= n) return true;
	else return false;
}

Link* Link::to_first()
{
	Link* p = new Link();
	*p = *this;
	while (p->prev)
	{
		*p = *p->prev;
	}
	while (p->lower)
	{
		*p = *p->lower;
	}
	return p;
}

Link* Link::to_first_elem()
{
	Link* p = new Link();
	p = this;
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

Link* Link::find(Link* n)
{
	if (n == 0) return 0;

	n = n->to_first();

	while (n)
	{
		if (n->level == level && n->value == value) return n;
		n = n->succ;
	}

	return 0;
}

Link* Link::find_value_of(Link *n)
{
	Link* p = new Link();
	p = this;

	p = p->to_first();

	while (p)
	{
		if (n->value == p->value) return p;
		if (p->value == system_length && )
		p = p->succ;
	}

	return 0;
}

Link* Link::add(Link* n) // Добавляем элемент с таким-же значением, слоем выше.
{
	if (this == 0) error("Element does not exist");

	Link* p = new Link();

	p = this->find_value_of(n); // Находим аналог на первом уровне
	p->upper = n;
	n->lower = p;

	return this;
}

Link* Link::insert(Link* n)   // insert n before this object; return n
{
	if (n->value < 1 || n->value > system_length) error("Too low/high value in inserted link");
	if (n == 0) return this;
	if (this == 0) return n;

	while (true)
	{
		while (this->find(n) != 0) // Проверка на присутствие свободных слотов на этом уровне.
		{
			if (n->value >= system_length) n->level++;
			else n->value = randint(1, 10);
		}
		if (n->value > this->value) // Если элемент больше по значению, добавляем его после данного элемента.
		{
			if (succ) succ->prev = n;
			n->succ = succ;
			n->prev = this;
			succ = n;

			return n;
		}
		else						// Если элемент меньше по значению, вставляем его до этого элемента.
		{
			n->succ = this;           // this object comes after n
			if (prev) prev->succ = n;
			n->prev = prev;           // this object's predecessor becomes n's predecessor
			prev = n;                 // n becomes this object's predecessor

			return n;
		}
	}
}

Link* Link::generate()
{
	Link* n = new Link ();
	n->value = randint(1, 10);
	n->level = 1;

	Link* p = this;

	if (this->find_value_of(n) != 0)  // Если есть элемент на уровне ниже, то уже добавляем новый элемент слоем выше него.
		{
		n->level++;
		if (make_decision(100/(n->level - 0.6))) p = p->add(n);
		else return n;
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

//===================================================================================================================

Link* Link::fill_level(Link* sys, int l)
{
	for (int i = 2; i < 11; i++)
	sys = sys->insert(new Link(i, l));

	sys = sys->to_first();

	for (int i = 2; i < 5; i++)
	{
		sys = sys->add(new Link(1, i));
	}

	sys = sys->to_first();
	return sys;
}

void Link::print_all()
{
	*this = *this->to_first();
	while (true)
	{

	}
}

//===================================================================================================================

int main()
{
	Link* linksys = new Link(1, 1);
	linksys = linksys->fill_level(linksys, 1);

	while (true)
	{
		linksys = linksys->generate();
	}
}
