#ifndef TEMPLATES_H
#define TEMPLATES_H

#endif // TEMPLATES_H
#include "/home/kordax/Code/lib/std_lib_facilities.h"

using namespace std;

template <class T> struct S
{
private:
    T val;
public:
    S(T t) : val(t) { cout << "Constructor called" << endl; }
    S() {};
    ~S() { cout << "Destructor called" << endl; }

    void set_val(int i);
    T& get();
};

template <class T>
istream& operator>> (istream& is, S<T>& tс)
{
    is >> tс;
    return is;
}

template<class T> void S<T>::set_val(int i)
{
    S::val = i;
}

template<class T> T& S<T>::get()
{
    return val;
}
