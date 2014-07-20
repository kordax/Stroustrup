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
    counted_ptr& operator=(const counted_ptr&);
    counted_ptr& operator=(const T&);
    ~counted_ptr();

public: // access

//=========

private: // check_null

void check_not_null_ptr() const;

private: // pointers

    T* in_ptr;
    reference_count* counter;

};

template <class T>
counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr& obj)
{
    if (this != &obj) // Проверяем адрес?!
    {
        if (in_ptr != 0)
        {
            delete in_ptr;
        }
        in_ptr = obj.in_ptr;
    }

    return *this;
}

template <class T>
counted_ptr<T>& counted_ptr<T>::operator=(const T& obj)
{
    in_ptr = obj;
}
