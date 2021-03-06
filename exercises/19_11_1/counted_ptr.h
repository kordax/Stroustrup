#ifndef COUNTED_PTR_H
#define COUNTED_PTR_H

#endif // COUNTED_PTR_H

#include <reference_count.h>


template <class T>
class counted_ptr
{
public: // create/copy/destroy

    //counted_ptr();
    counted_ptr(T* ptr = 0, reference_count* ref_cnt = new reference_count())
        :in_ptr(ptr), counter(ref_cnt) {}
    counted_ptr(const counted_ptr&); // copy constructor

    counted_ptr& operator=(counted_ptr&);
    counted_ptr& operator=(const counted_ptr&);
    counted_ptr& operator=(const T&);
    counted_ptr& operator==(const T&);
    counted_ptr& operator==(const counted_ptr&);
    T& operator->();

    ~counted_ptr();

public: // access

//=========

private: // check_null

void is_null() const;

public: // pointers

    T* in_ptr;
    reference_count* counter;

};

template <class T>
counted_ptr<T>::counted_ptr(const counted_ptr& obj)
{
    if (this != &obj)
    {
        in_ptr = obj.in_ptr;
        counter = obj.counter;
        counter->increment(); // Увеличиваем значение счётчика
    }
}

template <class T>
counted_ptr<T>& counted_ptr<T>::operator ==(const T& obj)
{
    if (in_ptr == obj) return true;
    return false;
}

template <class T>
counted_ptr<T>& counted_ptr<T>::operator ==(const counted_ptr& obj)
{
    if (in_ptr == obj.in_ptr) return true;
    return false;
}

template <class T>
counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr& obj)
{
    if (this != &obj)
    {
        in_ptr = obj.in_ptr;
        counter = obj.counter;
        counter->increment(); // Увеличиваем значение счётчика
    }
    return *this;
}

template <class T>
counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr<T>& obj)
{
    if (this != &obj)
    {
        in_ptr = obj.in_ptr;
        counter = obj.counter;
        *counter++; // Увеличиваем значение счётчика
    }
    return *this;
}

template <class T>
counted_ptr<T>& counted_ptr<T>::operator=(const T& obj)
{
    in_ptr = obj;
}

template <class T>
counted_ptr<T>::~counted_ptr()
{
    if (*in_ptr != NULL)
    {
        delete in_ptr;
    }
    if (*counter->counter != NULL)
    {
        delete counter;
    }
}

template <class T>
T& counted_ptr<T>::operator ->()
{
    return *in_ptr;
}
