#include "/media/kordax/WD/Bjorn/std_lib_facilities.h"

//===================================================================================================================

class Link {
public:
    int value;
    int level;

    Link(int v, Link* p = 0, Link* s = 0)
        : value (v), prev(p), succ(s), level(1) { }

    Link(Link* p = 0, Link* s = 0) { }

    Link* insert(Link* n);   // insert n before this object
    Link* add(Link* n);      // insert n after this object
    Link* erase();           // remove this object from list
    Link* find(Link* n);    // find s in list

    void next();
    Link* previous() { return prev; }
    Link* to_first();
    Link* to_last();

    Link* add_ordered(Link* p);
    Link* advance(int n);
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

Link* Link::find(Link* n)
{
    Link* p = n;

    p = p->to_first();

    while (p)
    {
        if (p->level == level && p->value == value) return p;
        p = p->succ;
    }

    return 0;
}

Link* Link::add(Link* n) //insert n after this object
{
    if (this->find(n)) return this;
    if (n == 0) return this;
    if (this == 0) return n;

    if (succ) succ->prev = n;
    n->succ = succ;
    n->prev = this;

    succ = n;
    return n;
}

Link* Link::insert(Link* n)   // insert n before this object; return n
{
    if (n->value < system_length) error("Too low value in inserted link");
    if (n == 0) return this;
    if (this == 0) return n;

    Link* p = new Link(1);

    while (true)
    {
        while (this->find(n)) // Проверка на присутствие свободных слотов на этом уровне.
            {
            if (p->value >= system_length) p->level++;
            else    p->value++;
            }
        while (this->find(n)) // Проверка на присутствие элемента на этом уровне.
            {
                n->value = randint(1, 10);

            }

        n->succ = this;           // this object comes after n
        if (prev) prev->succ = n;
        n->prev = prev;           // this object's predecessor becomes n's predecessor
        prev = n;                 // n becomes this object's predecessor
        return n;
    }
}

Link* Link::add_ordered(Link* n)
{
    if (n == 0) return this;
    if (this == 0) return n;

    int i = 0;
    int i2 = 0;
}

//===================================================================================================================



//===================================================================================================================

int main()
{
    Link* linksys = linksys->insert(new Link(rand() % 10 + 1));

}
