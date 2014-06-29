#include <iostream>
#include "templates.h"

using namespace std;

int main()
{
    S<int> s_int(1235);
    S<char> s_char('t');
    S<double> s_double(25.2);
    S<string> s_string("Test string");
    S< vector <int> > s_vec(vector<int>(3));
    cout << s_int.val << endl;
    cout << s_double.val << endl;
    cout << s_char.val << endl;
    cout << s_string.val << endl;
    cout << s_vec.val[1] << endl;
    return 0;
}
