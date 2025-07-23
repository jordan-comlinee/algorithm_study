#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool findVal(int val, vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == val)
        {
            return true;
        }
    }
    return false;
}

int solution(int n, vector<int> lost, vector<int> reserve) {

    vector<int> rlost = lost;
    vector<int> rreserve = reserve;

    sort(rlost.begin(), rlost.end());
    sort(rreserve.begin(), rreserve.end());

    for (int i = 0; i < rlost.size(); )
    {
        if (findVal(rlost[i], rreserve))
        {
            for (int j = 0; j < rreserve.size(); ++j)
            {
                if (rreserve[j] == rlost[i])
                {
                    rreserve.erase(rreserve.begin() + j);
                    break;
                }
            }
            rlost.erase(rlost.begin() + i);
        }
        else
        {
            ++i;
        }
    }

    int lostAmount = rlost.size();

    for (int i = 0; i < rlost.size(); ++i)
    {
        for (int j = 0; j < rreserve.size(); ++j)
        {
            if (rlost[i] - 1 == rreserve[j] || rlost[i] + 1 == rreserve[j])
            {
                lostAmount--;
                rlost[i] = -10;
                rreserve[j] = 40;
            }
        }
    }

    return n - lostAmount;
}