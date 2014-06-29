#include <iostream>
#include <vector>
#include <memory>

/*template <class T>
class auto_ptr {
private:
    T* inner_pointer;
    T* release();
public:
    explicit auto_ptr(T* reference = 0) throw() :inner_pointer(reference) {}
    ~auto_ptr() throw();

    T* operator -> () { return inner_pointer; }
    T& operator * () { return *inner_pointer; }
};

template <class T>
auto_ptr<T>::auto_ptr(T* reference = NULL) throw()
{
    inner_pointer = reference;
}

template <class T>
auto_ptr<T>::~auto_ptr() throw()
{
    delete inner_pointer;
}
*/

using namespace std;

int main()
{
    auto_ptr< vector<int> > p(new vector<int>);
    p->at(5) = 3;
    cout << "Hello World!" << endl;
    return 0;
}

