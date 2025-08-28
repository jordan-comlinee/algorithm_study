#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };


int bfs(const pair<int, int>& start, const pair<int, int>& end, const vector<string>& board)
{
    int c = board.size();
    int r = board[0].size();
    bool visited[100][100][4] = { false };
    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < 4; ++i)
    {
        q.push({ start.first, start.second, i, 0 });
        visited[start.first][start.second][i] = true;
    }
    while (!q.empty())
    {
        auto [x, y, dir, move] = q.front();
        q.pop();
        if (x == end.first && y == end.second) return move;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x;
            int ny = y;
            while (true)
            {
                int tx = nx + dx[i];
                int ty = ny + dy[i];
                if (tx < 0 || tx >= c || ty < 0 || ty >= r || board[tx][ty] == 'D')
                    break;
                nx = tx;
                ny = ty;
            }
            if (!visited[nx][ny][i])
            {
                visited[nx][ny][i] = true;
                q.push({ nx, ny, i, move + 1 });
            }
        }
    }
    return -1;
}


int solution(vector<string> board) {
    int answer = 0;
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == 'R') start = { i, j };
            if (board[i][j] == 'G') end = { i, j };
        }
    }

    answer = bfs(start, end, board);


    return answer;
}