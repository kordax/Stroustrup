// Files2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

struct Point {
public:
	int x;
	int y;

	Point() :x(0), y(0) {};
};

ostream& operator<<(ostream& os, const Point& pt)
{
	os << "x: " << pt.x << ' ' << "y: " << pt.y << ';';
	return os;
}

istream& operator>>(istream& is, Point& pt)
{
	int x, y;
	char ch1, ch2;

	if (is >> ch1 >> ch2 >> x >> ch1 >> ch2 >> y && ch1 != 'x' && ch1 != 'y' && ch2 != ':' && ch2 != '=')
	{
		is.unget();
		is.clear(ios::failbit);
		return is;
	}
	pt.x = x;
	pt.y = y;
	return is;
}

ostream& operator<<(ostream& os, const vector<Point>& pt)
{
	for (int i = 0; i < pt.size(); ++i)
	{
		os << pt[i] << endl;
	}
	return os;
}

istream& operator>>(istream& is, vector<Point>& pt)
{
	int x, y;
	Point p;
	is >> p;
	pt.push_back(p);
	return is;
}

int main()
{
	vector<Point> points;
	vector<Point> originalpoints;
	vector<Point> processed_points;
	string name;
	Point pt;
	int i = 0;

	cout << "Enter your points: " << '\n';
	cin >> pt;
	points.push_back(pt);
	cout << points;

	cout << "Enter file name: ";
	cin >> name;

	ofstream ofs(name.c_str());
	if (!ofs) error("can't open file", name);
	ofs << points;
	ofs.close();

	ifstream ifs(name.c_str());
	if (!ifs) error("can't open file", name);
	ifs >> processed_points;

	cout << points;
	cout << processed_points;
	keep_window_open();
	return 0;
}