#include <iostream>
#include <malloc.h>

using namespace std;

template <class T>
class myalloc {
public:
    T* allocate(int n);
    void deallocate(T* p, int n);
    void construct(T* p, const T& t);
    void destroy(T* p);
};

template <class T>
T* myalloc<T>::allocate(int n)
{
    T* p;
    p = (T*) malloc(n * sizeof(T));
    return p;
}

template <class T, class A = myalloc<T> >
class mystack {
    public:
    A myalloc;
    T* data;
    unsigned short int size;
    unsigned short int max_size;

    mystack() :size(0) {};
    mystack(unsigned short int sz) : max_size(sz), size(0) {};

    mystack& push_back(const T&);
    int get(int n);
    T& operator[](int i);
};

template <class T, class A>
mystack<T, A>& mystack<T, A>::push_back(const T& o)
{
    if (size == 0)
        {
            T* p = myalloc.allocate(6);
            data = p;
        }
    data[size] = o;
    size++;

    return *this;
}

template <class T, class A>
T& mystack<T, A>::operator[](int i)
{
    return data[i];
}

template <class T, class A>
int mystack<T, A>::get(int n)
{
    return data[n];
}

int main()
{
    mystack<int> test;
    int i = 2;

    test.push_back(i);
    test.push_back(3);
    test.push_back(63);
    cout << test[0] << endl << test[1] << endl << test[2] << endl;

    return 0;
}
