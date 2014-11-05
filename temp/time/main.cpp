#include <iostream>
#include <syscall.h>
#include <time.h>

using namespace std;

int main()
{
    timespec tp;
    if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp)) cout << "gettime error";
    else
    cout << "TP: " << endl << "Sec: " << tp.tv_sec/100 << endl << "NSec: " << tp.tv_nsec/100 << endl;
    cout << "Hello World!" << endl;
    return 0;
}

