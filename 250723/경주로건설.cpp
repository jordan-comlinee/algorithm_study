#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<vector<int>> gboard;

int price[30][30][4];

struct State {
    int x, y, dir, cost;
};

bool check_valid(int x, int y)
{
    return (x >= 0) && (x < gboard.size()) && (y >= 0) && (y < gboard[0].size()) && gboard[x][y] != 1;
}

void BFS_Find_Route(int x, int y)
{
    queue<State> Q;

    for (int i = 0; i < 30; ++i)

        for (int j = 0; j < 30; ++j)

            for (int d = 0; d < 4; ++d)

                price[i][j][d] = 1e9;

    for (int dir = 0; dir < 4; ++dir)
    {
        price[x][y][dir] = 0;
        Q.push({ x, y, dir, 0 });
    }

    while (!Q.empty())
    {
        State curr = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = curr.x + dx[dir];
            int ny = curr.y + dy[dir];

            if (!check_valid(nx, ny)) continue;

            int new_cost = curr.cost + (curr.dir == dir ? 100 : 600);

            //방향 바뀌면 회전비 + 길 만드는 비용까지 레츠기릿

            if (price[nx][ny][dir] > new_cost)
            {
                price[nx][ny][dir] = new_cost;
                Q.push({ nx, ny, dir, new_cost });
            }
        }
    }
}

int solution(vector<vector<int>> board) {

    gboard = board;

    BFS_Find_Route(0, 0);

    int n = board.size();
    int m = board[0].size();

    int answer = 1e9;

    for (int i = 0; i < 4; ++i)
    {
        answer = min(answer, price[n - 1][m - 1][i]);
    }

    return answer;
}
