#include <templates.h>

using namespace std;

int main()
{
    vector< Number<int> > vec1(5);
    vector< Number<int> > vec2(6);
    vector< Number<int> > result;
    for (int i = 0; i < vec1.size(); i++)
    {
        vec1[i] = i + 1;
    }
    for (int i = 0; i < vec2.size(); i++)
    {
        vec2[i] = i + 1;
    }
    result = vec1 + vec2;
    cout << result[4] << endl;
    return 0;
}
