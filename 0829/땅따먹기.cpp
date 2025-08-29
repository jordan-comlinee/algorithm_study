#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int landSize = land.size();
    
    for(int i = 1; i < landSize; ++i)
    {
        int a = land[i - 1][0];
        int b = land[i - 1][1];
        int c = land[i - 1][2];
        int d = land[i - 1][3];
        
        land[i][0] += max({b, c, d});
        land[i][1] += max({a, c, d});
        land[i][2] += max({a, b, d});
        land[i][3] += max({a, b, c});
        
    }
    
    return *max_element(land.back().begin(), land.back().end());

}