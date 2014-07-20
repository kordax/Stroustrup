#include <iostream>
#include <counted_ptr.h>

using namespace std;

int main()
{
    int x = 1;

    counted_ptr<int> p = new int(1);

    cout << &x << endl;
    cout << "test" << endl;
    return 0;
}

