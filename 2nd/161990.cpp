# if 0
// seongho
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    
    int u = 2100000000, l = 2100000000, r = -1, d = -1;
    for(int i = 0; i<wallpaper.size(); i++)
    {
        for(int j = 0; j<wallpaper[0].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i < u)
                    u = i;
                if(i > d)
                    d = i;
                if(j < l)
                    l = j;
                if(j > r)
                    r = j;
            }
        }
    }
    answer[0] = u;
    answer[1] = l;
    answer[2] = d+1;
    answer[3] = r+1;
    return answer;
}
#endif
#if 0
// jihoon
#include <climits>
#include <iostream>
#include <string>
#include <vector>
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int rdx = -1, rdy = -1, lux = INT_MAX, luy = INT_MAX;
    int xSize = wallpaper.size();
    int ySize = wallpaper[0].size();
    cout << "전체 크기: " << xSize << ", " << ySize << endl;
    
    for(int x = 0; x < xSize; ++x)
    {
        int y = 0;
        for(const char& c : wallpaper[x])
        {
            if(c == '#')
            {
                if(luy > y)
                {
                    luy = y;
                }
                if(lux > x)
                {
                    lux = x;
                }
                if(luy != -1 && y > rdy)
                {
                    rdy = y;
                }
                if(lux != -1 && x > rdx)
                {                    
                    rdx = x;
                }
            }
            
            ++y;
        }        
    }
    
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx + 1);
    answer.push_back(rdy + 1);
    
    return answer;
}
#endif
