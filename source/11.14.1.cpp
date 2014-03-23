// 11.14.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

int main()
{
	vector<string> words;

	string inputfile, outputfile;
	inputfile = "E:\\input.txt";
	outputfile = "E:\\output.txt";
	ifstream ifs(inputfile.c_str());
	if (!ifs) error("Cannot open ", inputfile);
	ofstream ofs(outputfile.c_str());
	if (!ofs) error("Cannot open ", outputfile);

	double n;
	vector<double> base;
	while (ifs >> n)
	{
		base.push_back(n);
	}


	int cnt = 1;
	for (int i = 0; i < base.size(); ++i)
	{
		ofs << setw(20) << scientific << setprecision(8) << base[i];
		if (cnt % 4 == 0) ofs << '\n';
		++cnt;
	}
	return 0;
}