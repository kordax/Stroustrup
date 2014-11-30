#include <string.h>

using namespace std;

template<class T>
class allocat {
public:
T* allocate (int n);
void deallocate(T* p, int n);
void construct(T* p, const T& v);
void destroy(T* p);
};

template<class T>
T* allocat<T>::allocate(int n)
{
    if (n == 0) return NULL;
    T* p;
    p = (T*) malloc(n * sizeof(T));
    return p;
}

template<class T>
void allocat<T>::deallocate(T* p, int n)
{
    if (n == 0) return;
    for (int i = 0; i < n; i++)
    {
        free(p);
        p++;
    }
    return;
}

template<class T>
void allocat<T>::construct(T* p, const T& v)
{
    new (p) T(v); // Создаём объект T со значением v и присваиваем ему указатель
}

template<class T>
void allocat<T>::destroy(T* p)
{
    p->~T();
}
