#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int searching(const vector<string>& board, const int xSize, const int ySize, const int startX, const int startY, const int endX, const int endY, vector<vector<int>>& visited)
{    
    queue<pair<int,int>> q;
    q.push({startX, startY});

    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if(curX == endX && curY == endY)
        {
            return visited[curY][curX];
        }

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = curX;
            int ny = curY;
            
            while(true)
            {
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];
                if(tx < 0 || tx >= xSize || ty < 0 || ty >= ySize)
                {
                    break;
                }
                if(board[ty][tx] == 'D')
                {
                    break;
                }
                nx = tx;
                ny = ty;
            }

            if(visited[ny][nx] == -1)
            {
                visited[ny][nx] = visited[curY][curX] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    
    const int xSize = board[0].size();
    const int ySize = board.size();
    int startX;
    int startY;
    int endX;
    int endY;
    
    for(int y = 0; y < ySize; ++y)
    {
       for(int x = 0; x < xSize; ++x)
       {
           if(board[y][x] == 'R')
           {
               startX = x;
               startY = y;
           }
           else if(board[y][x] == 'G')
           {
               endX = x;
               endY = y;
           }           
       }
    }
    
    vector<vector<int>> visited(ySize, vector<int>(xSize, -1));
    visited[startY][startX] = 0;
    
    if(startX == endX && startY == endY)
    {
        return 0;
    }
    
    answer = searching(board, xSize, ySize, startX, startY, endX, endY, visited);
    
    return answer;
}