#include <templates.h>

using namespace std;

int main()
{
    S<int> s_int(2);
    S<double> s_double(2);
    S<char> s_char(2);
    s_int[1] = 25;
    S<string> s_string_1(3);
    S<string> s_string_2(5);
    S<vector <int> > s_vectors;
    cout << "s_int > ";
    cin >> s_int[1];
    cout << "s_double > ";
    read_val(s_double[0]);
    cout << "s_char > ";
    read_val(s_char[0]);
    cout << "s_string > ";
    read_val(s_string_1[0]);
    cout << "s_vector > ";
    int i;
    cin >> i;
    vector<int> vec;
    vec.push_back(i);
    s_vectors.push_back(vec);

    s_string_2[0] = "s_string_2 test";
    s_string_1 = s_string_2;

    cout << "s_int[1] = " << s_int[1] << endl;
    cout << "s_int[2] = " << s_int[2] << endl;
    cout << "s_double = " << s_double[0] << endl;
    cout << "s_char = " << s_char[0] << endl;
    cout << "s_string = " << s_string_1[0] << endl;
    cout << "s_vector = " << s_vectors[0] << endl;
    return 0;
}
