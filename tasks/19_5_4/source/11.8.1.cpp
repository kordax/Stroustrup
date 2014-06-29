// 11.8.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

int main()
try
{
	string name, name2;
	name = "E:\\binaryi.txt";
	name2 = "E:\\binaryo.txt";
	ifstream ifs(name.c_str());
	ofstream ofs(name2.c_str(), ios_base::binary);

	vector<int> v;
	
	int i;
	while (ifs >> i)
	v.push_back(i);

	for (int i = 0; i < v.size(); ++i)
		ofs.write(as_bytes(v[i]), sizeof(int));

	// Преобразование бинарного файла binaryo.xt в обычный
	
	ifs.close();
	ofs.close();

	string name3, name4;
	name3 = "E:\\binaryo.txt";
	ifstream ifs2(name3.c_str(), ios_base::binary);
	name4 = "E:\\converted.txt";
	ofstream ofs2(name4.c_str());

	vector<char> bin;

	char n;
	while (ifs2.read(as_bytes(n), sizeof(char)))
		bin.push_back(n);

	for (int i = 0; i < v.size(); ++i)
		ofs2.write(as_bytes(bin[i]), sizeof(int));
	return 0;
}

catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}