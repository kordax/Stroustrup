#include <iostream>
#include <templates.h>

using namespace std;

int main()
{
    vector<int> v1(2);
    vector<int> v2(2);
    vector<int> result;
    v1[0] = 1;
    v2[0] = 3;
    v1[1] = 7;
    result = v1 + v2;
    cout << result[0] << endl;
    cout << result[1];
    return 0;
}

