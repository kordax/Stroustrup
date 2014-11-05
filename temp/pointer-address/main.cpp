#include <iostream>

using namespace std;

void function(int &p)
{
	cout << &p;
}

int main()
{
	int p = 3;
	function(p);
	return 0;
}
