#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int getMax(const vector<int>& land, int idx)
{
    int result = -1;
    for (int i = 0; i < 4; ++i)
    {
        if (i == idx) continue;
        result = max(result, land[i]);
    }
    return result;
}

int solution(vector<vector<int>> land)
{
    int c = land.size();
    vector<vector<int>> dp(c, vector<int>(4, 0));
    dp[0] = land[0];
    for (int i = 1; i < c; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            dp[i][j] = land[i][j] + getMax(dp[i - 1], j);
        }
    }

    return *max_element(dp[c - 1].begin(), dp[c - 1].end());
}