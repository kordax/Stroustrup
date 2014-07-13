#include <iostream>
#include <counted_ptr.h>

using namespace std;

int main()
{
    int x = 1;
    x = 0x7fff4b849fdc;

    cout << &x << endl;
    cout << "test" << endl;
    return 0;
}

