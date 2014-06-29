#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <allocator.h>
//#include <memory>

using namespace std;

template <class T, class A = allocat<T> > class S
{
public:
    unsigned int buffer;
    unsigned int size;
    T* val;
    A alloc;
public:
    //S(T t) : val(t) { cout << "Constructor called" << endl; }

    S() :size(0), buffer(0), val(0) { cout << "Default constructor called" << endl; }
    S(const unsigned int newsize) :size(0), buffer(0), val(0) { resize(newsize); }
    ~S() { cout << "Destructor called" << endl; } //val && this->val выдавали разное значение??? Не ясно почему.

    void initialize(const unsigned int);
//===========================================================
    S& operator=(const S&);
    istream& operator>> (istream&);
    T& operator[](unsigned int);
    const T& operator[](const unsigned int) const;
    T& get_val();
    void set_val(const T&);
    void read_val (T&);
//===========================================================
    void reserve(const unsigned int);
    void resize(const unsigned int, T);
    void push_back(const T&);
//===========================================================

    //struct Irange_error;
};

//template <class T, class A>
struct Range_error
{
    Range_error(int index) { cout << "Error: out of range at [" << index << "] !"; }
};

struct Pointer_error
{
    Pointer_error(string str) { cout << "Error: * = " << str;}
};


template <class T, class A>
void S<T, A>::initialize(const unsigned int newsize)
{
    resize(newsize);
}

template <class T, class A>
void S<T, A>::reserve(const unsigned int newalloc)
{
    if (newalloc <= buffer) return;
    T* newmemory = alloc.allocate(newalloc);
    //=======================================================
    for (int i = 0; i < size; ++i)
    {
        alloc.construct(&newmemory[i], val[i]); // копируем
    }
    for (int i = 0; i < size; ++i)
    {
        alloc.destroy(&val[i]); // уничтожаем
    }
    //=======================================================
    alloc.deallocate(val, buffer); // освобождаем старую память
    val = newmemory;
    buffer = newalloc;
    //size = newalloc;
}

template <class T, class A>
void S<T, A>::resize(const unsigned int newsize, T obj = T())
{
reserve(newsize);
for (int i = size; i < newsize; ++i) alloc.construct(&val[i], obj);
// создаем
for (int i = newsize; i < size; ++i) alloc.destroy(&val[i]);
// унич т ожа ем
size = newsize;
}

template <class T, class A>
T& S<T,A>::operator[](unsigned int i)
{
    if (i < 0) throw Range_error(i);
    if (i > this->size) throw Range_error(i);
    return val[i];
}

template <class T, class A>
const T& S<T,A>::operator[](unsigned int i) const
{
    if (i < 0) throw Range_error(i);
    if (i > size) throw Range_error(i);
    return *val;
}

/*
template <class T, class A>
void S<T,A>::operator=(const string& str)
{
    this->val = str;
}
*/

template <class T, class A>
S<T,A>& S<T, A>::operator=(const S& obj)
// похож на конструктор копирования,
// но мы должны работать со старыми элементами
{
T* p = new T[obj.size];
for (int i = 0; i < obj.size; ++i) alloc.construct(&p[i], obj.val[i]);
// элементы
delete val; // освобождаем старую память
buffer = size = obj.size; // устанавливаем новый размер
val = p; // устанавливаем новые элементы

return *this; // возвращаем ссылку на себя
}

template <class T, class A>\
void S<T,A>::push_back(const T& t)
{
    if (buffer == 0) reserve(8);
    else if (buffer == size) reserve(2*buffer);
    val[size] = t;
    size++;
}

template <class T, class A>
T& S<T,A>::get_val()
{
    return *val;
}

template <class T, class A>
void S<T,A>::set_val(const T& t)
{
    *val = t;
}

template <class T, class A>
istream& operator>> (istream& is, S<T, A>& t)
{
    T input;
    is >> input;
    t.set_val(input);
    return is;
}

template <class T>
ostream& operator<< (ostream& os, const vector<T>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    os << vec[i];
    return os;
}

template <class T>
void read_val (T& t)
{
    cin >> t;
}
