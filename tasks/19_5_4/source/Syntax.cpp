// Syntax.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Syntax.h"
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

void swap(double& d1, double& d2)
{
	double temp = d1;
	d1 = d2;
	d2 = temp;
}

vector<int> vf;
vector<string> vs;
vector<int> age;

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) {}
};

class Token_stream {
private:
	bool full;
	Token buffer;
public:
	Token_stream();
	Token get();
	void unget(Token t);
	void ignore(char);
};

void swap(int& v1, int& v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

void swap_str(string& s1, string& s2)
{
	string temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}

void reverse_str(vector<string>& vec1, vector<int>& vecage)
{
	vector<string> vec2;
	for (int i = vec1.size() - 1; i >= 0; --i)
		vec2.push_back(vec1[i]);
	vec1 = vec2;
	vector<int> vecage2;
	for (int i = vecage.size() - 1; i >= 0; --i)
		vecage2.push_back(vecage[i]);
	vecage = vecage2;
}

void reverse_str2(vector<string>& vec1, vector<int>& vecage)
{
	for (int i = 0; i < vec1.size() / 2; ++i)
	{
		swap_str(vec1[i], vec1[vec1.size() - 1 - i]);
	}
	for (int i = 0; i < vecage.size() / 2; ++i)
	{
		swap(vecage[i], vecage[vecage.size() - 1 - i]);
	}
}

void reverse(vector<int>& vec1)
{
	vector<int> vec2;
	for (int i = vec1.size()-1; i >= 0; --i)
		vec2.push_back(vec1[i]);
	vec1 = vec2;
}

void reverse2(vector<int>& vec1)
{
	for (int i = 0; i < vec1.size() / 2; ++i)
	{
		swap(vec1[i], vec1[vec1.size() - 1 - i]);
	}
}

void print(vector<int>& vec, const string& name)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << name << " " << i << " = " << vec[i] << '\n';
	}
}

void print_str(vector<string>& vec, vector<int>& vecage, const string& name)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << name << " " << i << ": " << vec[i] << ", age " << vecage[i] << '\n';
	}
}

void fibonacci(int x, int y, vector<int>& vec, int n)
{

	if (n < 1)
	{
		cout << "n < 1";
		return;
	}
	if (n == 1)
	{
		cout << "n == 1";
		return;
	}
	vec.push_back(x);
	vec.push_back(y);
	int res;
		for (int i = 2; i < n; ++i)
		{
			res = vec[i - 2] + vec[i-1];
			vec.push_back(res);
		}
}

void writenames(vector<string>& vec, vector<int>& vecage, int counter)
{
	string vname;
	int vage;
	for (int i = 0; i < counter; ++i)
	{
		cout << "Enter " << i << " name and age: ";
		cin >> vname >> vage;
		vec.push_back(vname);
		vecage.push_back(vage);
	}
}

void writestrings(vector<string>& vec, int counter)
{
	string vname;
	int vage;
	for (int i = 0; i < counter; ++i)
	{
		cout << "Enter " << i << " string: ";
		cin >> vname;
		vec.push_back(vname);
	}
}

int find_index(const vector<string>& v, const string& n)
// find n's index in v
{
	for (int i = 0; i < v.size(); ++i)
	if (n == v[i]) return i;
	error("name not found: ", n);
}

// for (int i = 0; i < name.size(); ++i)		// update ages
// age[i] = original_ages[find_index(original_names, name[i])];

void sortvec(vector<string>& vec, vector<int>& vecage)
{
	vector<string> originalnames;
	vector<int> originalage;
	originalage = vecage;
	originalnames = vec;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
		vecage[i] = originalage[find_index(originalnames, vec[i])];
}

//===================================================================================

int randint(int &x, int m)
{
	int a = 8, c = 65;
	x = ((a * x) + c) % m;
	return (x / m);
}

void randomize(const int &numbers)
{
	double res;
	for (int i = 0; i < numbers; ++i)
	{
		res = randint(7);
		cout << res;
	}
	cout << endl;
}

double priceweight(vector<double> &price, vector<double> &weight, const int &n)
{
	double index = 0;
	double result;
	vector<double> mult;
	double val_price, val_weight;
	cout << "Enter the price and weight: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> val_price >> val_weight;
		price.push_back(val_price);
		weight.push_back(val_weight);
	}

	for (int i = 0; i < price.size() && weight.size() <= price.size(); ++i)
	{
		result = price[i] * weight[i];
		mult.push_back(result);
		index += mult[i];
	}

	return index;
}

int maxv(vector<int> &vec)
{
	int compare = vec[0];
	if (vec.size() == 1) return vec[0];
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i] >= vec[i - 1] && vec[i] >= compare) compare = vec[i];
	}
	return compare;
}

int minv(vector<int> &vec)
{
	int compare = vec[0];
	if (vec.size() == 1) return vec[0];
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i] <= vec[i - 1] && vec[i] <= compare) compare = vec[i];
	}
	return compare;
}

void medianf(vector<int> &vec, int &maximum, int &minimum, double &median, double &average)
{
	int max, min;
	int middle1, middle2;
	maximum = maxv(vec);
	minimum = minv(vec);
	sort(vec.begin(), vec.end());
	middle1 = (vec.size() / 2);
	if (vec.size() % 2 == 0)
	{
		middle2 = ((vec.size() / 2) + 1); // middle2 находится правее middle1, потому-что ряд чисел чётный.
		middle1 = vec[middle1 - 1]; // Элементы вектора начинаются с нуля, поэтому значения вектора
		middle2 = vec[middle2 - 1]; // находятся левее.
		median = double(middle1 + middle2) / 2;
	}
	else
	{
		middle1 = median = vec[middle1];
	}
	average = 0;
	for (int i = 0; i < vec.size(); ++i)
		average = average + vec[i];
	average /= 2;
}

vector<int> countchars(const vector<string> &vec)
{
	char ch;
	vector<int> quantity;
	for (int i = 0; i < vec.size(); ++i)
	{
		quantity[i] = vec[i].size();
		return quantity;
	}
}

int longest(const vector<string>& vec)
{
	if (vec.size() == 0) error("longest(): empty vector");	// protect against the empty string

	int m = vec[0].size();		// we now know that there is a v[0]
	int max_index = 0;
	for (int i = 0; i < vec.size(); ++i)
	if (m < vec[i].size()) {
		max_index = i;
		m = vec[i].size();
	}
	return max_index;
}

string& shortest(vector<string>& vec)
{
	string firststr = vec[0];
	int index;
	if (vec.size() == 0) error("longest(): empty vector");
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i].size() <= vec[i - 1].size() && vec[i].size() <= firststr.size())
		{
			firststr = vec[i];
			index = i;
		}
	}
	return vec[index];
}

string lex_first(const vector<string>& vec)
{
	if (vec.size() == 0) return "";	// the empty string is first

	int first_index = 0;
	for (int i = 0; i < vec.size(); ++i)
	if (vec[i] < vec[first_index])
		first_index = i;
	return vec[first_index];
}

void lex_last(vector<string>& vec, int& last)
{
	if (vec.size() == 0) {
		last = -1;	// -1 indicates "the empty vector"
		return;
	}

	int last_index = 0;
	for (int i = 0; i < vec.size(); ++i)
	if (vec[last_index] < vec[i])
		last_index = i;
	last = last_index;	// copy last_index out of function
}

void worklongest()
{
	string shortest_str;
	int longest_index;
	int n;
	cout << "How many names to write? : ";
	cin >> n;
	writestrings(vs, n);
	shortest_str = shortest(vs);
	longest_index = longest(vs);
	cout << "Shortest: " << shortest_str << '\n';
	cout << "Longest: " << vs[longest_index];
}

//===================================================================================

void workmedv()
{
	int max, min, elem;
	double med, aver;
	vector<int> maxv_vec;
	while (cin >> elem)
		maxv_vec.push_back(elem);
	medianf(maxv_vec, max, min, med, aver);
	cout << "Max = " << max << '\n';
	cout << "Min = " << min << '\n';
	cout << "Median = " << med << '\n';
	cout << "Average = " << aver << '\n';
}

//===================================================================================

void workpriceweight()
{
	double res;
	vector<double> pr, we;
	res = priceweight(pr, we, 5);
	cout << "Index = " << res << '\n';
}

//===================================================================================

void worknumbers()
{
	int first, second, vct_size;
	string rev;
	cout << "Please enter two numbers of Fibonacci:" << '\n';
	cout << "First: ";
	cin >> first;
	cout << "Second: ";
	cin >> second;
	cout << "Please enter the size of vector: ";
	cin >> vct_size;
	fibonacci(first, second, vf, vct_size);
	print(vf, "Element");
	cout << '\n' << "Type in 'reverse' or 'random' to randomize numbers vector: ";
	cin >> rev;
	if (rev == "reverse") reverse(vf);
	if (rev == "reverse2") reverse2(vf);
	if (rev == "random")
	{
		randomize(40);
	}
	print(vf, "Element");
	return;
}

//===================================================================================

void workstrings()
{
	int n;
	string name, rev;
	cout << "How many names to write? : ";
	cin >> n;
	writenames(vs, age, n);
	print_str(vs, age, "String");
	cout << '\n' << "Type in 'reverse' or 'reverse2' to reverse vectors or ";
	cout << '\n' << "type in 'sort' or to sort vectors. \n";
	cin >> rev;
	if (rev == "reverse") reverse_str(vs, age);
	if (rev == "reverse2") reverse_str2(vs, age);
	if (rev == "sort") sortvec(vs, age);
	print_str(vs, age, "String");
	return;
}

//===================================================================================

int main()
{
	string option;
	cout << "1 numbers, 2 strings, 3 weight-price, 4 median, 5 longest \n";
	cin >> option;
	if (option == "1") worknumbers();
	if (option == "2") workstrings();
	if (option == "3") workpriceweight();
	if (option == "4") workmedv();
	if (option == "5") worklongest();
	keep_window_open();
	return 0;
}