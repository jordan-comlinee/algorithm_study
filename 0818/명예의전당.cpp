#include <vector>
using namespace std;

bool hasSpace(vector<int> Scorelist, int k)
{
    if (Scorelist.size() >= k)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int getMin(vector<int> v)
{
    int minVal = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] < minVal)
            minVal = v[i];
    }
    return minVal;
}

int getMinIndex(vector<int> v)
{
    int minVal = v[0];
    int minIdx = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] < minVal)
        {
            minVal = v[i];
            minIdx = i;
        }
    }
    return minIdx;
}

vector<int> solution(int k, vector<int> score)
{
    vector<int> jundang;
    vector<int> presented;

    for (int s : score)
    {
        if (hasSpace(jundang, k))
        {
            jundang.push_back(s);
            presented.push_back(getMin(jundang));
        }
        else
        {
            if (getMin(jundang) <= s)
            {
                int index = getMinIndex(jundang);
                jundang[index] = s;
            }
            presented.push_back(getMin(jundang));
        }
    }

    return presented;
}
