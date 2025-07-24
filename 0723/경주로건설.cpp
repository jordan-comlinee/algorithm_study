#if 0
// seongho
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int R, C;
bool isIn(int r, int c)
{
    if(r==0 && c ==0)
        return false;
    if(0 <= r && r < R && 0 <= c && c < C)
        return true;
    return false;
}

int solution(vector<vector<int>> board)
{
    R = board.size();
    C = board[0].size();
    
    // visit 2개 벡터로 표시 (가로, 세로 움직임)
    vector<vector<int>> r(board.size(), vector<int>(board[0].size(), INT_MAX-1000));
    vector<vector<int>> c(board.size(), vector<int>(board[0].size(), INT_MAX-1000));
    
    // 좌표 이동
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    
    // BFS에 사용할 큐, 시작점(0,0) 삽입
    queue<pair<int, int>> q;
    q.push({0, 0});
    r[0][0] = 0;
    c[0][0] = 0;
    
    // BFS실행
    while(!q.empty())
    {
        int t_r = q.front().first;
        int t_c = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++)
        {
            int next_r = t_r+dr[i], next_c = t_c+dc[i];
            if(isIn(next_r, next_c) && !board[next_r][next_c])
            {
                if(i%2)
                {
                    int num_tmp = min(r[t_r][t_c]+100, c[t_r][t_c]+600);

                    if(r[next_r][next_c] > num_tmp)
                    {
                        r[next_r][next_c] = num_tmp;
                        q.push({next_r, next_c});
                    }
                    else
                        continue;
                }
                else
                {
                    int num_tmp = min(c[t_r][t_c]+100, r[t_r][t_c]+600);
                    if(c[next_r][next_c] > num_tmp)
                    {
                        c[next_r][next_c] = num_tmp;
                        q.push({next_r, next_c});
                    }
                    else
                        continue;                    
                }
            }
        }
    }
    
    // 최소값 반환
    return min(r[R-1][C-1], c[R-1][C-1]);
}
#endif

#if 0
// jihoon
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
#endif