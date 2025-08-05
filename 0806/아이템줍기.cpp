#include <string>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

bool board[101][101];
bool visited[101][101];



int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = -1;
    pair<int, int> character = { characterX * 2, characterY * 2 };
    pair<int, int> item = { itemX * 2, itemY * 2 };
    queue<pair<pair<int, int>, int>>q;
    q.push({ character, 0 });
    visited[characterX * 2][characterY * 2] = true;

    for (auto rect : rectangle)
    {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        for (int i = x1; i <= x2; ++i)
        {
            board[i][y1] = true;
            board[i][y2] = true;
        }
        for (int i = y1; i <= y2; ++i)
        {
            board[x1][i] = true;
            board[x2][i] = true;
        }
    }
    for (auto rect : rectangle)
    {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        for (int i = x1 + 1; i < x2; ++i)
        {
            for (int j = y1 + 1; j < y2; ++j)
            {
                board[i][j] = false;
            }
        }
    }

    while (!q.empty())
    {
        auto [cur, dist] = q.front();
        q.pop();
        if (cur == item) return dist / 2;

        for (int i = 0; i < 4; ++i)
        {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || ny < 0 || nx >= 101 || ny >= 101) continue;
            if (visited[nx][ny]) continue;
            if (!board[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({ {nx, ny}, dist + 1 });
        }
    }

    return answer;
}