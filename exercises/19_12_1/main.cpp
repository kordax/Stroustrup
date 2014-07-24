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
    file_stream = new fstream;
    file_stream->open(_filename.c_str(), ios_base::in | ios_base::out);
}

File_handle::~File_handle()
{
    file_stream->close();
    delete file_stream;
}

int main()
{
    File_handle("/home/kordax/file_handler.txt");
    return 0;
}

