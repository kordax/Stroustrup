#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <allocator.h>

using namespace std;

template <class T, class A = allocat<T> > struct S
{
public:
    unsigned int buffer;
    unsigned int size;
    T* val;
    A alloc;
public:
    //S(T t) : val(t) { cout << "Constructor called" << endl; }

    S() :size(0), buffer(0), val(0) { cout << "Default constructor called" << endl; }
    S(const unsigned int sz) :size(0), buffer(0), val(0) { resize(sz); }
    ~S() { alloc.deallocate(this->val, size); cout << "Destructor called" << endl; } //val && this->val выдавали разное значение??? Не ясно почему.
//===========================================================
    void operator=(const string&);
    istream& operator>> (istream&);
    T& operator[](unsigned int);
    const T& operator[](const unsigned int) const;
    T& get_val();
    void set_val(const T&);
    void read_val (T&);
//===========================================================
    void reserve(const unsigned int);
    void resize(const unsigned int);
    void push_back(const T&);
//===========================================================
};

template <class T, class A>
void S<T, A>::reserve(const unsigned int newalloc)
{
    if (newalloc <= buffer) return;
    T* newmemory = alloc.allocate(newalloc);
    for (int i = 0; i < size; i++) newmemory[i] = val[i];

    free(val);
    val = newmemory;

    buffer = newalloc;
}

template <class T, class A>
void S<T,A>::resize(const unsigned int newsize)
{
    if (newsize > size) reserve(newsize);
    if (newsize == size) return;
    if (newsize < size)
    {
        int cnt = 0;
        for (int i = 0; i < size; i++)
        {
            cnt++;
            if (i > newsize) delete val;
            val++;
        }
        val == val - cnt;
    }
}

template <class T, class A>
void S<T,A>::operator=(const string& str)
{
    this->val = str;
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
T& S<T,A>::operator[](unsigned int i)
{
    //if (i < 0) throw Range_error(i);
    //if (i > size) throw Range_error(i);
    return val[i];
}

template <class T, class A>
const T& S<T,A>::operator[](unsigned int i) const
{
    //if (i < 0) throw Range_error(i);
    //if (i > size) throw Range_error(i);
    return *val;
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
