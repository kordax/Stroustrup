#include <std_lib_facilities.h>

//===================================================================================================================

class Link {
public:
	int value;
	int level;
	int system_levels = 4;
	int system_length = 10;

	Link(int v, int l, Link* p = 0, Link* s = 0, Link* lo = 0, Link* up = 0)
		: value(v), prev(p), succ(s), lower(lo), upper(up), level(l) { }

	Link(Link* p = 0, Link* s = 0, Link* lo = 0, Link* up = 0)
		: prev(p), succ(s), lower(lo), upper(up) { }

	Link* insert(Link* n);   // insert n before this object
	Link* add(Link* n);  // ��������� ������� � �����-�� ���������, ����� ����.
	Link* find(Link* n);     // find s in list
	Link* find_lower(Link *n);
	Link* find_total(Link *n);
	Link* find_duplicate(Link *n);
	Link* generate();

	Link* to_first();
	Link* to_first_total();
	Link* to_level(int n);
	Link* to_last();
	Link* to_last_total();
	Link* advance();
	Link* reverse();
	Link* set_neighbours();

	Link* fill_level(Link* sys, int l);
private:
	Link* prev;
	Link* succ;
	Link* upper;
	Link* lower;
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
	Link* p = this;

	while (p->prev)
	{
		p = p->prev;
	}

	return p;
}

Link* Link::to_first_total()
{
	Link* p = this;

	while (p->lower)
	{
		p = p->lower;
	}
	while (p->prev)
	{
		p = p->prev;
	}
	return p;
}

Link* Link::to_last()
{
	Link* p = this;

	while (p->succ)
	{
		p = p->succ;
	}

	return p;
}

Link* Link::to_last_total()
{
	Link* p = this;

	p = p->to_first();

	while (p->upper)
	{
		p = p->upper;
	}
	while (p->succ)
	{
		p = p->succ;
	}
	return p;
}

Link* Link::advance()
{
	Link* p = this;

	if (p->value == system_length && p->level < system_levels)
	{
		p = p->to_first();
		if (p->upper) 
		{
			p = p->upper;
			return p;
		}
	}
	p = p->succ;
	return p;
}

Link* Link::reverse() // ������ ����� �� ���� ���
{
	if (!prev && !lower) return this; // ���� ���� ����� ������
	Link* p = this;

	if (p->value == 1 && p->level > 1)
	{
		if (p->lower) p = p->lower;
		p = p->to_last();
	}
	if (p->prev) p = p->prev;

	return p;
}

Link* Link::to_level(int n)
{
	Link* p = this;

	if (n < 1 || n > system_levels)
	{
		cout << "Wrong 'to_level' argument!";
		return 0;
	}

	while (p->level > n)
	{
		p = p->lower;
	}
	while (p->level < n)
	{
		p = p->upper;
	}

	return p;
}

Link* Link::find_total(Link *n)
{
	if (n == 0) return this;

	Link* p = this;

	p = p->to_first_total();

	while (p)
	{
		if (n->level == p->level && n->value == p->value) return n;
		p = p->advance();
	}

	return 0;
}

Link* Link::find(Link* n)
{
	Link* p = this;

	p = p->to_first();

	while (p)
	{
		if (n->level == p->level && n->value == p->value) return p;
		p = p->succ;
	}

	return 0;
}

Link* Link::find_lower(Link *n)
{
	Link* p = this;

	while (p->level > n->level - 1 && p->level > 1) p = p->to_first_total(); // ���� ����� �� ������ ����, p->level - 1

	while (p)
	{
		if (p->level == n->level && p->value == n->value) return p;
		p = p->advance();
	}

	return 0;
}

Link* Link::find_duplicate(Link *n)
{
	Link* p = this;

	p = p->to_first_total();

	while (p)
	{
		if (p->level == n->level && p->value == n->value) return p;
		p = p->advance();
	}

	return 0;
}

Link* Link::set_neighbours()
{
	Link* p = this;
	Link* mark = this;

	if (p->prev && p->succ) return p;

	p = p->to_first_total();

	while (p->level != level && p->value < this->value) // ���� ���� ������� �� ������ ������ � �����, �� ���������� ��� � ������.
	{ // ������� ����� �� ��� ���, ���� �� ����� ����� ������� �������� (prev) � (succ).
		if (p->upper && p->level < level) p = p->upper;
		if (p->level == level) // ���� ������ ������� �� ���� ������, �������� ��� � ��������� ����� ������.
		{
			mark = p;
			while (p->lower)
			{
				p = p->lower;
			}
		}

		if (p->succ) p = p->succ;
	}
	if (mark && mark != this)
	{
		this->prev = mark;
		this->prev->succ = this;
	}

	mark = 0;

	p = p->to_last();

	while (p->level != level && p->value > this->value) // ���� ����� ��� �������� succ
	{
		if (p->upper) p = p->upper;
		if (p->level == level)
		{
			if (p != this) mark = p;
			while (p->lower)
			{
				p = p->lower;
			}
		}

		if (p->prev) p = p->prev;
	}

	if (mark && mark != this)
	{
		this->succ = mark;
		this->succ->prev = this;
	}

	return this;
}

Link* Link::add(Link* n) // ��������� ������� � �����-�� ���������, ����� ����.
{
	Link* p = this;

	/*
	p = p->to_last_total();
	p = p->to_first(); // ������ �� ������ ������� ���������� ������ (4)
	*/
	while (p)
	{
		if (n->value <= p->value) // ��������������� ������� �������
		{
			if (n->level < system_levels && n->level == level) n->level = p->level + 1;
			p->upper = n;
			n->lower = p;

			//n = n->set_neighbours();
			return n;
		}

		if (p->succ) p = p->succ;

	}

	return this;
}

Link* Link::insert(Link* n)   // insert n before this object; return n
{
	if (n->value < 1 || n->value > system_length) error("Too low/high value in inserted link");
	if (n == 0) return this;
	if (this == 0) return n;

	while (true)
	{
		while (this->find(n) != 0) // �������� �� ����������� ��������� ������ �� ���� ������.
		{
			if (n->value >= system_length) n->level++;
			else n->value = randint(1, 10);
		}
		if (n->value > this->value) // ���� ������� ������ �� ��������, ��������� ��� ����� ������� ��������.
		{
			if (succ) succ->prev = n;
			n->succ = succ;
			n->prev = this;
			succ = n;

			return n;
		}
		else						// ���� ������� ������ �� ��������, ��������� ��� �� ����� ��������.
		{
			n->succ = this;           // this object comes after n
			if (prev) prev->succ = n;
			n->prev = prev;           // this object's predecessor becomes n's predecessor
			prev = n;                 // n becomes this object's predecessor

			return n;
		}
	}
}

int cnt = 1;

Link* Link::generate()
{
	Link* n = new Link();
	n->value = randint(1, 10);
	n->level = 1;

	Link* p = this;

	if (p->find_total(n) != 0)  // ���� ���� ������� �� ������ ����, �� ��� ��������� ����� ������� ����� ���� ����.
	{
		p = p->find_lower(n);
		n->level++;
		if (p->find_total(n) != 0) // ���� ��� ������� n->level 2
		{
			p = p->find_lower(n); // p ��� ����� �������� n->level 2
			n->level++; // ���� ���� - ��������� n �� ������ �������, n->level ���� 3
		}
		if (make_decision(100 / (n->level - 0.6))) // ��� ������� �������� �������.
		{
			
			cout << "Decision true on p value: " << n->value << ", level: " << n->level << " #" << cnt << '\n';
			p = p->add(n);
			cnt++;
		}
		else 
		{ 
			cout << "Decision false on p value: " << n->value << " level: " << n->level << '\n';
			return this; 
		}
		p = p->set_neighbours();
		return p;
	}
	if (p->find_total(n) != 0)
	{
		if (p->level + 1 < system_levels) 
		return this;
	}
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

//===================================================================================================================

// �������� �������� ������� �� 3++ ������

int main()
{
	Link* linksys = new Link(1, 1);
	linksys = linksys->fill_level(linksys, 1);

	while (true)
	{
		linksys = linksys->generate();
	}
}
