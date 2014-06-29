#include <vector>

template <class T>
std::vector<T> operator+ (const std::vector<T>& t1, const std::vector<T>& t2)
{
    std::vector<T> result;

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
