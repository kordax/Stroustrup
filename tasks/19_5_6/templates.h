#include <iostream>

using namespace std;

template <class T> struct S
{
private:
    T val;
public:
    S(T t) : val(t) { cout << "Constructor called" << endl; }
    S() { cout << "Default constructor called" << endl; }
    ~S() { cout << "Destructor called" << endl; }


    void set_val(T);

    istream& operator>> (istream& is);
    T& get_val();
};

template <class T>
T& S<T>::get_val()
{
    return val;
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
