#include <iostream>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	const char *memname = "/mymem";		
	const size_t region_size = sysconf(_SC_PAGE_SIZE);
	
	int fd = shm_open(memname, O_CREAT | O_TRUNC | O_RDWR, 0666); // Создаём область разделяемой памяти
	int r = ftruncate(fd, region_size); // Распределяем пространство области
	
	void *ptr = mmap(0, region_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);	

	close(fd);

	pid_t pid = fork();

    if (pid == 0) {
        int *i = (int *) ptr;
        *i = 300;
        exit(0);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }

	return 0;
}
