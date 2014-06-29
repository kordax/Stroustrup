#include "templates.h"

using namespace std;

int main()
{
    S<int> s_int(123);
    S<char> s_char('t');
    S<double> s_double(1.2);
    S<string> s_string("teststr");
    //S< vector <int> > s_vec(vector<int>(3));
    cout << "s_int = ";
    cin >> s_int;
    cout << endl;
    //=================
    cout << "s_char = ";
    cin >> s_int;
    cout << endl;
    //=================
    cout << "s_double = ";
    cin >> s_int;
    cout << endl;
    //=================
    cout << "s_string = ";
    cin >> s_int;
    cout << endl;
    //=================
    /*cout << "s_vec = ";
    cin >> s_int;
    cout << endl;*/
    //=================
    cout << s_int.get() << endl;
    cout << s_char.get() << endl;
    cout << s_double.get() << endl;
    cout << s_string.get() << endl;
    //cout << s_vec[1].get() << endl;
    return 0;
}
