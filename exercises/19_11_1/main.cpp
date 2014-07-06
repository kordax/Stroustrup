#include <iostream>

template <class T>
class counted_ptr{
public:

    counted_ptr(T* object);

private:

    T* pointer;
    int counter;
};

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

