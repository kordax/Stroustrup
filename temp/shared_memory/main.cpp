#include <allocator.h>

int main()
{
    kordax::shmem_ruler<int> ruler;
    kordax::frame_s<int> myframe = ruler.to_memory(1, "/mymem");

    int *ptr = myframe.addr;
    *ptr = 1;

    std::cout << "I'm parent process! My int is " << *ptr << std::endl;

   pid_t pid = fork();

    if (pid == 0) {
        *ptr = *ptr++;
        std::cout << "I'm child process! My int is " << *ptr << std::endl;
        return(0);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}
