#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#endif // ALLOCATOR_H

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <unistd.h>

namespace kordax {

template <class A>
struct frame_s {
    int fd;
    std::string memn;
    A *addr;
    int quantity;
};

template <class A>
class shmem_ruler {
public:
    frame_s<A> to_memory(int n, const std::string);

    shmem_ruler() {};
    ~shmem_ruler() {};
};

template <class A>
frame_s<A> shmem_ruler<A>::to_memory(int n, const std::string memname)
{
    frame_s<A> frame;
    char *region_name = new char[memname.length() + 1];
    strcpy(region_name, memname.c_str());
    const size_t frame_size = sizeof(A) * n;

    int fd = shm_open(region_name, O_CREAT | O_TRUNC | O_RDWR, 0666); // Создаём область разделяемой памяти
    int r = ftruncate(fd, frame_size); // Распределяем пространство области

    void *ptr = mmap(0, frame_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); // Отображаем область в память для данного процесса

    frame.addr = (A*)ptr;
    frame.fd = fd;
    frame.memn = memname;
    frame.quantity = n;
    close(fd);

    return frame;
}
/*
template <class A>
shmem_ruler<A>::shmem_ruler()
{
}

template <class A>
shmem_ruler<A>::~shmem_ruler()
{
}
*/
}
