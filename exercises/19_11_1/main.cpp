#include <iostream>
#include <counted_ptr.h>

using namespace std;

int main()
{
    int x = 1;

    counted_ptr<int> p = new int(1);
    counted_ptr<int> p2 = p;

    cout << &x << endl;
    cout << "test" << endl;
    return 0;
}

