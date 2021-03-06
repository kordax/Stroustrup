#include <iostream>
#include <vector>

template <class T>
class auto_ptr {
private:
    T* inner_pointer;
public:
    explicit auto_ptr(T* reference = 0) throw() :inner_pointer(reference) {}
    ~auto_ptr() throw();

    T* release();

    T* operator -> () { return inner_pointer; }
    T& operator * () { return *inner_pointer; }
};

template <class T>
auto_ptr<T>::~auto_ptr() throw()
{
    delete inner_pointer;
}

template <class T>
T* auto_ptr<T>::release()
{
    T* temp = this->inner_pointer;
    this->inner_pointer = NULL;
    return temp;
}

using namespace std;

int main()
{
    auto_ptr< vector<int> > p1(new vector<int> (7));
    auto_ptr< vector<int> > p2(new vector<int> (3));
    p1->at(5) = 3; // Правильное поведение
    cout << (*p1).at(5) << endl;
    p2->at(5) = 3; // Exception
    return 0;
}
