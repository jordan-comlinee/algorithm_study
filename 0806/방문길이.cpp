#include <string>
using namespace std;

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int solution(string dirs) {
    int answer = 0;
    
    // (x, y, dir)
    bool visited[11][11][4] = { false };
    
    int cX = 0;
    int cY = 0;
    
    for(const char& dir : dirs)
    {
        int nX = cX;
        int nY = cY;
        
        int d;
        int cd;
        
        if(dir == 'U')
        {
            nY = cY + 1;
            d = UP;
            cd = DOWN;
        }
        else if(dir == 'D')
        {
            nY = cY - 1;
            d = DOWN;
            cd = UP;
        }
        else if(dir == 'R')
        {
            nX = cX + 1;
            d = RIGHT;
            cd = LEFT;
        }
        else if(dir == 'L')
        {
            nX = cX - 1;
            d = LEFT;
            cd = RIGHT;
        }
        
        if(nX < -5 || nX > 5 || nY < -5 || nY > 5)
        {
            continue;
        }
        
        int cxI  = cX + 5;
        int cyI  = cY + 5;
        int nxI  = nX + 5;
        int nyI  = nY + 5;
        
        if(!visited[cxI][cyI][d])
        {
            visited[cxI][cyI][d] = true;
            visited[nxI][nyI][cd] = true;
            ++answer;
        }
        
        cX = nX;
        cY = nY;

    }
    
    return answer;
}