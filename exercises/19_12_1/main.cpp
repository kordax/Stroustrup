#include <iostream>
#include <fstream>

using namespace std;

class File_handle
{
public:
    File_handle();
    File_handle(const string&);
    ~File_handle();

    string _filename;

private:
    fstream* file_stream;
};

File_handle::File_handle(const string& string)
{
    _filename = string;
    file_stream = new fstream;
    file_stream->open(_filename.c_str(), ios::out);
    *file_stream << "test";
}

File_handle::~File_handle()
{
    file_stream->close();
    file_stream->open(_filename.c_str(), ios::out);
    delete file_stream;
}

int main()
{
    File_handle handler("file_handler.txt");
    return 0;
}

