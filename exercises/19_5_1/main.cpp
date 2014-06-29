#include <iostream>

using namespace std;

class Int
{
private:

int value;

public:

Int() {}
~Int() {}
Int(int i) :value(i) {}

friend const Int& operator+ (const Int&);
friend const Int operator- (const Int&);
friend const Int& operator+ (const Int&, const Int&);
friend const Int& operator- (const Int&, const Int&);
const Int operator* (const Int&);
const Int operator/ (const Int&);

friend ostream& operator<< (ostream&, const Int&);
friend istream& operator>> (istream&, Int&);

//=====================================================================

Int& operator=(const Int& right) {
        //проверка на самоприсваивание
        if (this == &right) {
            return *this;
        }
        value = right.value;
        return *this;
    }

};

const Int& operator+(const Int& i) {
    return i.value;
}

const Int operator-(const Int& i) {
    return Int(-i.value);
}

const Int& operator+ (const Int& i_left, const Int& i_right)
{
    return i_left.value + i_right.value;
}

ostream& operator<< (ostream& os, const Int& i)
{
    os << i.value;
    return os;
}

istream& operator>> (istream& is, Int& i)
{
    is >> i.value;
    return is;
}

int main()
{
    Int n1;
    Int n2;
    cin >> n1;
    cin >> n2;
    Int result = n1 + n2;
    cout << result << endl;
    return 0;
}

