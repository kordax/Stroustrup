#ifndef COUNTED_PTR_H
#define COUNTED_PTR_H

#endif // COUNTED_PTR_H

#include <reference_count.h>

template <class T>
class counted_ptr
{
public: // create/copy/destroy

    counted_ptr(T*);
    counted_ptr(const counted_ptr& obj_to_copy);
    counted_ptr& operator=(const counted_ptr& obj_to_copy);
    ~counted_ptr();

public: // access

//=========

private: // check_null

void check_not_null_ptr() const;

private: // pointers

    T* inner_pointer;
    reference_count* counter;
};
