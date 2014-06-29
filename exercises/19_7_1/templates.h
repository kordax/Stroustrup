#ifndef TEMPLATES_H
#define TEMPLATES_H

#endif // TEMPLATES_H

#include <std_lib_facilities.h>

using namespace std;

template <class T>
class Number;

template <class T>
ostream& operator<< (ostream& os, const Number<T>& i);

template <class T>
istream& operator>> (istream& is, Number<T>& i);

template <class T>
const Number<T>& operator+ (const Number<T>&, const Number<T>&);

template <class T>
const Number<T>& operator- (const Number<T>&, const Number<T>&);

template <class T>
const Number<T>& operator+ (const Number<T>&);

template <class T>
const Number<T> operator- (const Number<T>&);

template <class T>
class Number
{
private:

T value;

public:

bool ok_;
explicit Number<T>( bool b=false):ok_(b) {}

operator bool() const {
    if (!value) return false;
    else return true;
}

//Number<T>() {} //Произвёл конверсию bool, т.е. по дефолту объект создан.
~Number<T>() {}
Number<T>(int i) :value(i) {}

friend const Number<T>& operator+ <>(const Number<T>&);
friend const Number<T> operator- <>(const Number<T>&);
friend const Number<T>& operator+ <>(const Number<T>&, const Number<T>&);
friend const Number<T>& operator- <>(const Number<T>&, const Number<T>&);
//const Number<T> operator* (const Number<T>&);
//const Number<T> operator/ (const Number<T>&);


friend ostream& operator<< <>(ostream& os, const Number<T>& i);
friend istream& operator>> <>(istream& is, Number<T>& i);

//=====================================================================

Number<T>& operator=(const Number<T>& right) {
        //проверка на самоприсваивание
        if (this == &right) {
            return *this;
        }
        value = right.value;
        return *this;
    }

};

template <class T>
const Number<T>& operator+ (const Number<T>& i) {
    return i.value;
}

template <class T>
const Number<T> operator- (const Number<T>& i) {
    return Number<T>(-i.value);
}

template <class T>
const Number<T>& operator+ (const Number<T>& i_left, const Number<T>& i_right)
{
    Number<T> res;
    res.value = i_left.value + i_right.value;
    return res;
}

template <class T>
const Number<T>& operator- (const Number<T>& i_left, const Number<T>& i_right)
{
    Number<T> res;
    res.value = i_left.value - i_right.value;
    return res;
}

template <class T>
ostream& operator<< (ostream& os, const Number<T>& i)
{
    os << i.value;
    return os;
}

template <class T>
istream& operator>> (istream& is, Number<T>& i)
{
    is >> i.value;
    return is;
}



//====================================================================================

template <class T>
vector<T> operator+ (vector<T>& t1, vector<T>& t2)
{
    vector<T> result;

    if (t1.size() > t2.size())
    {
        result.resize(t1.size());
        int oldsize = t1.size() - t2.size();
        t2.resize(t1.size());
        t2[t1.size() - oldsize] = 0;
    }
    else
    {
        result.resize(t2.size());
        int oldsize = t2.size() - t1.size();
        t1.resize(t2.size());
        t1[t2.size() - oldsize] = 0;
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (t1[i] && t2[i]) result[i] = t1[i] + t2[i];
        else
        {
            if (t1[i]) result[i] = t1[i];
            else result[i] = t2[i];
        }
    }
    return result;
}

template <class T, class U>
int function(const vector<T>& vt, const vector<U>& vu)
{
    unsigned int result = 0;
    if (vt.size() != vu.size()) throw Range_error(1);
    for (int i = 0; i < vt.size(); i++)
    {
        result += vt[i] * vu[i];
    }

    return result;
}
