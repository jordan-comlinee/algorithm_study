#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long>> board(n + 1, vector<long long>(m + 1, 0));
    board[0][0] = 1;
    for (auto puddle : puddles)
    {
        board[puddle[1] - 1][puddle[0] - 1] = -1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            long long path = 0;
            if (i == 0 && j == 0) continue;
            if (board[i][j] == -1)
            {
                board[i][j] = 0;
                continue;
            }
            if (i > 0) path += board[i - 1][j];
            if (j > 0) path += board[i][j - 1];
            board[i][j] = path % 1000000007;
        }
    }
    return board[n - 1][m - 1];
}