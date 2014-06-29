#include <iostream>

using namespace std;

template <class T> struct S
{
private:
    T val;
public:
    S(T t) : val(t) { cout << "Constructor called" << endl; }
    S() { cout << "Default23 constructor called" << endl; }
    ~S() { cout << "Destructor called" << endl; }

    void set_val(int i);
    T& get();
};

template <class T>
istream& operator>> (istream& is, S<T> t)
{
    is >> t;
    return is;
}
