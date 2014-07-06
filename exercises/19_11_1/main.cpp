#include <iostream>
#include <counted_ptr.h>

template <class T>
counted_ptr<T>::counted_ptr(T* object_pointer = NULL)
{
    inner_pointer = object_pointer;

}

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

