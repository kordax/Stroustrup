#include <templates.h>

using namespace std;

int main()
{

    S<int> s_int(2);
    S<double> s_double(2);
    S<char> s_char(2);
    S<string> s_string(3);
    S<vector <int> > s_vectors;
    cout << "s_int > ";
    cin >> s_int[0];
    cout << "s_double > ";
    cin >> s_double[0];
    cout << "s_char > ";
    cin >> s_char[0];
    cout << "s_string > ";
    cin >> s_string[0];
    cout << "s_vector > ";
    int i;
    cin >> i;
    vector<int> vec;
    vec.push_back(i);
    s_vectors.push_back(vec);

    cout << "s_int = " << s_int[0] << endl;
    cout << "s_double = " << s_double[0] << endl;
    cout << "s_char = " << s_char[0] << endl;
    cout << "s_string = " << s_string[0] << endl;
    vec = s_vectors[0];
    cout << "s_vector = " << vec[0] << endl;
    return 0;
}
