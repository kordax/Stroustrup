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
    size_t f_size;
};

template <class A>
class shmem_ruler {
public:
    frame_s<A> map(int n, const std::string);
    void unmap(A* ptr, const size_t f_size);

    shmem_ruler() {};
    ~shmem_ruler() {};
};

template <class A>
frame_s<A> shmem_ruler<A>::map(int n, const std::string memname)
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
    frame.f_size = frame_size;
    close(fd);

    return frame;
}

template <class A>
void shmem_ruler<A>::unmap(A* ptr, const size_t f_size)
{
    if (munmap(ptr, f_size) == 0);
}
}
