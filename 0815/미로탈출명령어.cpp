#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#if 0
    
    사전순
    d : down
    l : left
    r : right
    u : up
        
    k 이동 -> 문자열 사전 순 가장 빠른 경로

#endif

const char moving[4] = {'d','l','r','u'};
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, -1, 1, 0 };

string bfs(const int& n, const int& m, const int& startX, const int& startY, const int& endX, const int& endY, const int& k)
{
    vector<vector<int>>maze(n + 1, vector<int>(m + 1, 0));
    queue<int> q;
    
    string path;
    
    int cX = startX;
    int cY = startY;

    for(int movedCnt = 0; movedCnt < k; ++movedCnt)
    {
        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cX + dx[dir];
            int ny = cY + dy[dir];
            
            if(nx < 1 || nx > n || ny < 1 || ny > m)
            {
                continue;
            }

            int howManyCan = k - (movedCnt + 1);
            int need = abs(nx - endX) + abs(ny - endY);

            if(need <= howManyCan)
            {
                path.push_back(moving[dir]);
                cX = nx;
                cY = ny;
                
                break;
            }
        }
    }

    return path;        
}


string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    #if 0
    파람파람
    격자 크기: (n, m)
    시작 지점: (x, y)
    종료 지점: (r, c)
    이동 거리: 총 k
    #endif
        
    const int startX = x;
    const int startY = y;
    const int endX = r;
    const int endY = c;
    
    if(k < abs(endX - startX) + abs(endY - startY))
    {
        return "impossible";
    }
    
    answer = bfs(n, m, startX, startY, endX, endY, k);
    
    if(answer.size() != k)
    {
        return "impossible";
    }
    
    return answer;
}