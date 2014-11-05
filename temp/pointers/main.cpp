#include <iostream>

using namespace std;

void f(int* p)
{
    static int* obj = new int;
    *obj = 5;
    *p = *obj;
}
 
int main()
{
    int* a = new int[3];
    a[2] = 3;
    
    f(&a[2]);
    
    cout << a[2] << endl; // выведет 3
}
