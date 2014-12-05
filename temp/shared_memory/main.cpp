#include <allocator.h>

int main()
{
    kordax::shmem_ruler<int> ruler;
    kordax::frame_s<int> myframe = ruler.map(1, "/mymem");

    int *ptr = myframe.addr;
    *ptr = 1;

    std::cout << "I'm parent process! My int is " << *ptr << std::endl;

   pid_t pid = fork();

    if (pid == 0) {
        return(0);
    }
    else {
        int status;
        *ptr = 2;
        std::cout << "I'm child process! My int is " << *ptr << std::endl;
        waitpid(pid, &status, 0);
    }

    ruler.unmap(ptr, myframe.f_size);

    return 0;
}
