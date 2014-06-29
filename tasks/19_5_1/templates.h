#ifndef TEMPLATES_H
#define TEMPLATES_H

#endif // TEMPLATES_H
#include "/home/kordax/Code/lib/std_lib_facilities.h"

using namespace std;

template<class T> struct S
{
private:
    T val;
public:
    S(T t) : val(t) { std::cout << "Constructor called" << std::endl; }
    S() {};
    ~S() { std::cout << "Destructor called" << std::endl; }

    void set_val(const char &ch);
    T& get();

    std::istream& operator >> (std::istream& is);
};

template<class T>
std::istream& operator >> (std::istream& is, S<T> &t)
{
    const char ch;
    is >> ch;
    t.set_val(ch);
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
