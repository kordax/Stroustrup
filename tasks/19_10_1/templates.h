#include <std_lib_facilities.h>

using namespace std;

template <class T> struct S
{
public:
    T val;
public:
    S(T t) : val(t) { cout << "Constructor called" << endl; }
    S() { cout << "Default constructor called" << endl; }
    ~S() { cout << "Destructor called" << endl; }


    void set_val(T);

    istream& operator>> (istream& is);
    T& operator[](unsigned int);
    const T& operator[](const unsigned int) const;
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
T& S<T>::operator[](unsigned int i)
{
    if (i<0) throw Range_error(i);
    return T::operator[](i);
}


template <class T>
const T& S<T>::operator[](unsigned int i) const
{
    if (i<0) throw Range_error(i);
    return val[i];
}

template <class T>
istream& operator>> (istream& is, S<T> &t)
{
    T input;
    is >> input;
    t.set_val(input);
    return is;
}
