#include <iostream>
#include <fstream>

using namespace std;

class File_handle
{
public:
    File_handle();
    File_handle(const string&);
    ~File_handle();

private:
    fstream* file_stream;
};

File_handle::File_handle(const string& _filename)
{

}

int main()
{
    return 0;
}

