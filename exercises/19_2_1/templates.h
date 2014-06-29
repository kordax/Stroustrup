#include <std_lib_facilities.h>

using namespace std;

template <class T>
vector<T> operator+ (const vector<T>& t1, const vector<T>& t2)
{
    vector<T> result;

    if (t1.size() > t2.size())
    {
        result.resize(t1.size());
    }
    else
    {
        result.resize(t2.size());
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (t1[i] && t2[i]) result[i] = t1[i] + t2[i];
        else
        {
            if (t1[i]) result[i] = t1[i];
            else result[i] = t2[i];
        }
    }
    return result;
}

template <class T, class U>
int function(const vector<T>& vt, const vector<U>& vu)
{
    unsigned int result = 0;
    if (vt.size() != vu.size()) throw Range_error(1);
    for (int i = 0; i < vt.size(); i++)
    {
        result += vt[i] * vu[i];
    }

    return result;
}
