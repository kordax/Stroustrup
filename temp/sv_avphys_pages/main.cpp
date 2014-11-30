#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <syscall.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;

int main (int argc, char *argv[])
{
    string num_pages;
    num_pages = sysconf( _SC_AVPHYS_PAGES );
    istringstream os(num_pages);
    int i;
    os >> i;
    cout << i << endl;
    return 0;
}
