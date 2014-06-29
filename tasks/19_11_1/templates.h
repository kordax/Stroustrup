#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T> struct S
{
private:
    unsigned int buffer;
    unsigned int size;
    T* val;
public:
    //S(T t) : val(t) { cout << "Constructor called" << endl; }

    S() :size(0), buffer(0), val(0) { cout << "Default constructor called" << endl; }
    S(const unsigned int sz) :size(0), buffer(0), val(new T[sz]) {}
    ~S() { delete[] val; cout << "Destructor called" << endl; }
//===========================================================
    T& operator=(T&);
    istream& operator>> (istream&);
    T& operator[](unsigned int);
    const T& operator[](const unsigned int) const;
    T& get_val();
    void set_val(T);
//===========================================================
    void reserve(const unsigned int);
    void resize(const unsigned int);
    void push_back(const T&);
//===========================================================
};

template <class T>
void S<T>::reserve(const unsigned int newalloc)
{
    if (newalloc <= buffer) return;
    T* newmemory = new T[newalloc];
    for (int i = 0; i < size; i++) newmemory[i] = val[i];

    delete[] val;
    val = newmemory;

    buffer = newalloc;
}

template <class T>
void S<T>::resize(const unsigned int newsize)
{
    if (newsize > size) reserve(newsize);
    {
        for (int i = size; i < newsize; i++)
        {
            val[i] = 0;
        }
    }
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

template <class T>\
void S<T>::push_back(const T& t)
{
    if (buffer == 0) reserve(8);
    else if (buffer == size) reserve(2*buffer);
    val[size] = t;
    size++;
}

template <class T>
T& S<T>::operator[](unsigned int i)
{
    //if (i < 0) throw Range_error(i);
    //if (i > size) throw Range_error(i);
    return val[i];
}

template <class T>
const T& S<T>::operator[](unsigned int i) const
{
    //if (i < 0) throw Range_error(i);
    //if (i > size) throw Range_error(i);
    return val[i];
}

template <class T>
T& S<T>::get_val()
{
    return *val;
}

template <class T>
void S<T>::set_val(T t)
{
    val = t;
}


template <class T>
istream& operator>> (istream& is, S<T> &t)
{
    T input;
    is >> input;
    t.set_val(input);
    return is;
}
