// Files3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

struct Reading {
	int day;
	int hour;
	double temperature;

	Reading() :day(0), hour(0), temperature(0.0) {};
};

ostream& operator<<(ostream& os, const Reading& r)
{
	os << "Day: " << r.day << ' ' << "Hour: " << r.hour << ' ' << "Temperature: " << r.temperature << '\n';
	return os;
}

istream& operator>>(istream& is, Reading& r)
{
	string day, hour, temp;
	int d, h;
	double t;
	if (!is) return is;
	is >> day >> d >> hour >> h >> temp >> t;
	if (day != "Day:" || hour != "Hour:" || temp != "Temperature:")
	{
		is.seekg(is.beg);
		is.clear(ios_base::failbit);
		return is;
	}
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

istream& operator>>(istream& is, vector<Reading>& vec)
{
	Reading r;
	if (!(is >> r)) return is;
	vec.push_back(r);
	return is;
}

void fill_readings(vector<Reading> &vec)
{
	Reading r;
	int d = 1;
	for (int i = 1; i <= 10; ++i)
	{
		r.day = d;
		for (int h = 0; h < 24 && vec.size() < 50; ++h)
		{
			r.hour = h;
			r.temperature = i;
			vec.push_back(r);
			if (h == 24) h = 0;
		}
		if (++d > 31) d = 1;
	}
}

void read_from_file(const vector<Reading>& vec, istream& is)
{
	Reading r;
	is >> r;
}

double medianf(const vector<Reading> &vec)
{
	double mid1, mid2;
	double med;
	mid1 = vec[vec.size() / 2].temperature;
	if ((vec.size() % 2) == 0) // 1 3 7 9 mid1 равняется трём. (4 / 2)
	{
		mid2 = vec[++mid1].temperature;
		med = (mid1 + mid2) / 2;
		return med;
	}
	mid1 = vec[++mid1].temperature; // 1 3 7 mid1 и есть медиана. 3 элеметна разделить на 2 = 1. mid1 = vec[1], поэтому прибавляем единицу.
	med = mid1;
	return med;
}

int main()
{
	vector<Reading> readings;
	fill_readings(readings);
	vector<Reading> input;
	string name, name2;
	double median = 0, average = 0;
	//==================
	cout << "Enter output file name: ";
	cin >> name;
	ofstream os(name.c_str());
	if (!os) error("Cannot open file for writing");
	for (int i = 0; i < readings.size(); ++i)
	{
		os << readings[i];
	}
	os.close();
	//==================
	cout << "Enter input file name: ";
	cin >> name2;
	ifstream is(name2.c_str());
	if (!is) error("Cannot open file for reading");
	while (true)
	if (!(is >> input)) break;
	is.close();
	//====
	for (int i = 0; i < input.size(); ++i)
	{
		average += input[i].temperature;
	}
	average /= 2;
	median = medianf(input);
	cout << "Average: " << average;
	cout << "Median: " << median;
	keep_window_open();
	return 0;
}

