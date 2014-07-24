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
    new (file_stream) fstream();
    file_stream->open(_filename.c_str(), ios_base::in | ios_base::out);
}

File_handle::~File_handle()
{
    delete file_stream;
}

int main()
{
    File_handle("test.txt");
    return 0;
}

