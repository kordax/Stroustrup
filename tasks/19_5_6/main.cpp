#include <iostream>
#include <templates.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    S<int> s_int;
    S<double> s_double;
    S<char> s_char;
    S<string> s_string;
    S<vector <int> > s_vector;
    cout << "s_int = " << endl;
    cin >> s_int;
    cout << "s_double = " << endl;
    cin >> s_double;
    cout << "s_char = " << endl;
    cin >> s_char;
    cout << "s_string = " << endl;
    cin >> s_string;
    cout << "s_vector = " << endl;
    cin >> s_vector;
    return 0;
}
