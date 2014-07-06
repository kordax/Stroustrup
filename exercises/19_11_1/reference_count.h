#ifndef REFERENCE_COUNT_H
#define REFERENCE_COUNT_H

#endif // REFERENCE_COUNT_H

class reference_count
{
public: // create/copy/destroy

    reference_count();
    reference_count(const reference_count&);
    reference_count& operator=(const reference_count&);
    ~reference_count();

private:

    void increment() { *counter++;}

    int* counter;
};

reference_count::reference_count()
    :counter(new int(1))
{

}


reference_count::reference_count(const reference_count& obj_to_copy)
    :counter(obj_to_copy.counter)
{
    increment();
}
