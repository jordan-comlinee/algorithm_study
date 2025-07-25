#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;    
    
    #if 0
    
    int topFloor;    
    n % w ? topFloor = n / w + 1 : topFloor = n / w;
    
    int curX = -1;
    int curY = 0;
    bool lTr = true;
    
    for(int curNum = 1, curFloor = 1; curFloor <= topFloor; ++curFloor)
    {
        for(int width = 0; width < w; ++width)
        {
            // 시작 좌 우
            if(!(curNum % w))
            {
                lTr ? lTr = false : lTr = true;                
            }
            if(lTr)
            {
                ++curX;
            }
            else
            {
                --curX;
            }
            
            if(curNum == num)
            {
                return (topFloor - curFloor) + 1;
            }
            
            ++curNum;
        }
        ++curY;
    }
    #endif
    
    #if 0
    
    vector<int> numList;
    for(int curFloor = 1; curFloor <= topFloor; ++curFloor)
    {
        if(curFloor % 2)    // 홀수 층
        {
            for(int curX = 1; curX <= w; ++curX)
            {
                int num = curFloor * w - (w - curX);
                numList.emplace_back(num);
            }
        }
        else
        {
            for(int curX = 1; curX <= w; ++curX)
            {
                int num = curFloor * w - (curX - 1);
                numList.emplace_back(num);
            }
        }
        
    }
    #endif
    
    #if 01
    
    int targetFloorIdx = (num - 1) / w + 1;
    int targetXIdx = (num - 1) % w;
    int xPos = (targetFloorIdx % 2 == 1) ? (targetXIdx + 1) : (w - targetXIdx);     // 홀수 | 쩌ㅏㄱ수
    int topFloor = (n + w - 1) / w;
    
    for(int curFloor = targetFloorIdx; curFloor <= topFloor; ++curFloor)
    {
        int startNum = (curFloor - 1) * w + 1;
        int endNum = min(curFloor * w, n);
        int floorSize = endNum - startNum + 1;

        if(curFloor % 2 == 1)   // 홀수층
        {
            if(xPos <= floorSize)
            {
                ++answer;
            }
        }
        else
        {
            if(xPos >= w - floorSize + 1) 
            {
                ++answer;
            }
        }
    }
    
    #endif
    
    return answer;
}