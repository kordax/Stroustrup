//------------------------------------------------------------------------------

// class used to report range access errors
struct out_of_range
{
    out_of_range(const std::string& error_message) {}
};

//------------------------------------------------------------------------------

struct Range_error : out_of_range { // enhanced vector range error reporting
    int index;
    Range_error(int i) :out_of_range("Range error"), index(i) { }
};

//------------------------------------------------------------------------------

template<class T> struct Vector : public std::vector<T> {
    typedef typename std::vector<T>::size_type size_type;

    Vector() { }
    Vector(size_type n) :std::vector<T>(n) {}
    Vector(size_type n, const T& v) :std::vector<T>(n,v) {}

    T& operator[](unsigned int i) // rather than return at(i);
    {
        if (i<0||this->size()<=i) throw Range_error(i);
        return std::vector<T>::operator[](i);
    }

    const T& operator[](unsigned int i) const
    {
        if (i<0||this->size()<=i) throw Range_error(i);
        return std::vector<T>::operator[](i);
    }
};

//------------------------------------------------------------------------------


//
// This is example code from Chapter 19.3.6 "Generalizing vector" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);            // allocate space for n objects of type T
    void deallocate(T* p, int n);  // deallocate n objects of type T starting at p

    void construct(T* p, const T& v); // construct a T with the value v in p
    void destroy(T* p);            // destroy the T in p
};

//------------------------------------------------------------------------------

template<class T, class A = allocator<T> > class vector {
    A alloc;    // use allocate to handle memory for elements
    int sz;     // the size
    T* elem;    // a pointer to the elements
    int space;  // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }
    vector(int s);
    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment
    ~vector() { delete[ ] elem; }     // destructor

    void resize(int newsize, T def = T()); // growth
    void push_back(const T& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;     // never decrease allocation
    T* p = alloc.allocate(newalloc); // allocate new space
    for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // copy
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);        // destroy
    alloc.deallocate(elem,space);    // deallocate old space
    elem = p;
    space = newalloc;
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::push_back(const T& val)
{
    // no more free space: get more
    if (space==0)
        reserve(8);
    else
    if (space==sz)
        reserve(2*space);

    alloc.construct(&elem[sz],val);  // add val at end
    ++sz;                            // increase the size
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val); // construct
    for (int i = newsize; i<sz; ++i) alloc.destroy(&elem[i]); // destroy
    sz = newsize;
}

//------------------------------------------------------------------------------

template<class T, class A> T& vector<T,A>::operator[](int n)
{
return elem[n];
}

//------------------------------------------------------------------------------

struct No_default {
    No_default(int);               // the only constructor for No_default
    // ...
};

//------------------------------------------------------------------------------
