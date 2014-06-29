#include <iostream>
#include "templates.h"

using namespace std;

int main()
{
    S<int> s_int;
    S<char> s_char;
    S<double> s_double;
    S<string> s_string;
    S< vector <int> > s_vec(vector<int>(3));
    cout << "s_int = " << endl;
    cin >> s_int;
    cout << "s_double = " << endl;
    cin >> s_double;
    cout << "s_char = " << endl;
    cin >> s_char;
    cout << "s_string = " << endl;
    cin >> s_string;
    cout << "s_vec = " << endl;
    cin >> s_vec;
    return 0;
}
