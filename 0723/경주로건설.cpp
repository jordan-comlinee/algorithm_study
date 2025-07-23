#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    vector<vector<vector<int>>> costs(N, vector<vector<int>>(N, vector<int>(4, INT32_MAX)));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < 4; ++i)
    {
        costs[0][0][i] = 0;
        q.push({ 0, 0, i });
    }
    while (!q.empty())
    {
        auto [x, y, dir] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int cost = dir == i ? 100 : 600;
            if (0 <= nx && nx < N && 0 <= ny && ny < N && board[nx][ny] == 0 && costs[x][y][dir] + cost < costs[nx][ny][i])
            {
                costs[nx][ny][i] = costs[x][y][dir] + cost;
                q.push({ nx, ny, i });
            }
        }
    }
    return *min_element(costs[N - 1][N - 1].begin(), costs[N - 1][N - 1].end());
}