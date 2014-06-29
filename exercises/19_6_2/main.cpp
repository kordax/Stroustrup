//#include <std_lib_facilities.h>
#include <iostream>

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

Number<T>() {}
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

int main()
{
    Number<int> n1;
    Number<int> n2;
    cin >> n1;
    cin >> n2;
    Number<int> result;
    result = n1 - n2;
    cout << result << endl;
    return 0;
}
