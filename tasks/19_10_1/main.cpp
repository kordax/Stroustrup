#include <templates.h>
#include <stdlib.h>

using namespace std;

int main()
{
    S<int> s_int;
    S<double> s_double;
    S<char> s_char;
    S<string> s_string;
    S<vector <int> > s_vector;
    cout << "s_int > ";
    cin >> s_int;
    cout << "s_double > ";
    cin >> s_double;
    cout << "s_char > ";
    cin >> s_char;
    cout << "s_string > ";
    cin >> s_string;
    cout << "s_vector > ";
    int i;
    cin >> i;
    vector<int> vec;
    vec.push_back(i);
    s_vector.set_val(vec);

    cout << "s_int = " << s_int.get_val() << endl;
    cout << "s_double = " << s_double.get_val() << endl;
    cout << "s_char = " << s_char.get_val() << endl;
    cout << "s_string = " << s_string[1] << endl;
    vec = s_vector.get_val();
    cout << "s_vector = " << vec[0] << endl;
    return 0;
}
