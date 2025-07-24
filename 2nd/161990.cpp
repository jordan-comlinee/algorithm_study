#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

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