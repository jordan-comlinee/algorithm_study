#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i = 1; i<land.size(); i++)
    {
        for(int j = 0; j<4; j++)
        {
            int m = 0;
            for(int k = 0; k<4; k++)
            {
                if(k==j)
                    continue;
                if(land[i-1][k] >m)
                    m = land[i-1][k];
            }
            land[i][j]+=m;
        }
    }
    for(int i = 0; i<4; i++)
    {
        if(land[land.size()-1][i]>answer)
            answer = land[land.size()-1][i];
    }
    return answer;
}
