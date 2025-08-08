#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(vector<vector<bool>>& map, int characterX, int characterY, int itemX, int itemY)
{
    int dist = 0;
    vector<vector<int>> visited(52, vector<int>(52, 0));
    queue<pair<int, int>>q;
    q.push({characterX, characterY});
    
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        if(curX == itemX && curY == itemY)
        {
            return visited[curY][curX];
        }
        
        for(int i = 0; i < 4; ++i)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX >= 1 && nextX <= 50 && nextY >= 1 && nextY <= 50 && map[nextY][nextX] && visited[nextY][nextX] == 0)
            {
                q.push({nextX, nextY});
                visited[nextY][nextX] = visited[curY][curX] + 1;
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    int rectangleSize = rectangle.size();
    
    vector<vector<bool>> map(51, vector<bool>(51, false));
    
    for(auto r : rectangle)
    {
        int x1 = r[0];
        int y1 = r[1];
        int x2 = r[2];
        int y2 = r[3];
        
        for(int x = x1; x <= x2; ++x)
        {
            map[y1][x] = true;
            map[y2][x] = true;
        }
        for(int y = y1; y <= y2; ++y)
        {
            map[y][x1] = true;
            map[y][x2] = true;
        }
        for(int x = x1 + 1; x < x2; ++x)
        {
            for(int y = y1 + 1; y < y2; ++y)
            {
                map[y][x] = false;
            }
        }
    }
    
    answer = bfs(map, characterX, characterY, itemX, itemY);
    
    return answer;
}