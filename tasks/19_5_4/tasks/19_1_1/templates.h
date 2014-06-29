#ifndef TEMPLATES_H
#define TEMPLATES_H

#endif // TEMPLATES_H
#include <vector>

class T;

template<class T> struct S
{
public:
    T val;

    S(T t) : val(t) { std::cout << "Constructor called" << std::endl; }
    ~S() { std::cout << "Destructor called" << std::endl; }
};
/*template< std::vector<int> > struct S
{
public:
    vector<T> val;

    S(vector<T> t) : val(t) { std::cout << "Constructor called" << std::endl; }
    ~S() { std::cout << "Destructor called" << std::endl; }

    T get_val() { return val; }
};
*/
