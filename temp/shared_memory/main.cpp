#include <allocator.h>

int main()
{
    kordax::shmem_ruler<int> ruler;
    ruler.map(1, "/mymem");

    int *ptr = ruler.frame.addr;
    *ptr = 1;

   pid_t pid = fork();

    if (pid == 0) { // Это дочерний процесс
        *ptr = 2;
        std::cout << "I'm child process! My int is " << *ptr << std::endl;
        std::cout << "My PID is: " << getpid() << " and my fork returned value is: " << pid << std::endl;
        return(0);
    }
    else { //
        int status;
        std::cout << "I'm parent process! My int is " << *ptr << std::endl;
        std::cout << "My PID is: " << getpid() << std::endl << std::endl;
        waitpid(pid, &status, 0);
    }

    ruler.unmap(ptr, ruler.frame.f_size);

    return 0;
}
