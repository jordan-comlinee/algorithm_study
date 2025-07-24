#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct route
{
    int y;
    int x;
    int dir;
    int cost;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(const int& boardSize, vector<vector<int>>& board)
{
    vector<vector<vector<int>>> routeCost(boardSize, vector<vector<int>>(boardSize, vector<int>(4, INT_MAX)));
    
    queue<route> q;    
    
    int minCost;
    
    for (int dir = 0; dir < 4; ++dir) 
    {
        int ny = dy[dir];
        int nx = dx[dir];

        if(ny >= 0 && ny < boardSize && nx >= 0 && nx < boardSize && board[ny][nx] == 0)
        {
            routeCost[ny][nx][dir] = 100;
            q.push({ ny, nx, dir, 100 });
        }
    }
    
    while (!q.empty()) 
    {
        auto c = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; ++dir)
        {
            int ny = c.y + dy[dir];
            int nx = c.x + dx[dir];
            if(ny < 0 || ny >= boardSize || nx < 0 || nx >= boardSize || board[ny][nx] == 1)
            {
                continue;
            }

            int newCost = c.cost + ((c.dir == dir) ? 100 : 600);
            if (routeCost[ny][nx][dir] > newCost)
            {
                routeCost[ny][nx][dir] = newCost;
                q.push({ ny, nx, dir, newCost });
            }
        }
        
        minCost = INT_MAX;
        for(int dir = 0; dir < 4; ++dir)
        {
            minCost = min(minCost, routeCost[boardSize - 1][boardSize - 1][dir]);
        }
    }

    return minCost;
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    
    // N X N, 0-BASED
    // 비어; 0
    // 벽: 1
    // 인접한 두 빈칸 연결하여 건설 가능
    // 두 빈칸 연결 = 직선
    // 두 직선 = 코너
    // 1 직선 = 100원
    // 1 코너 = 500 추가
    // 최소 비용?
    
    const int boardSize = board.size();
    answer = bfs(boardSize, board);
    
    return answer;
}