#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int N = board.size();
    int M = board[0].size();
    vector<vector<int>> plus(N + 1, vector<int>(M + 1, 0));

    for (const auto& s : skill) {
        int type = s[0];
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = s[5];
        if (type == 1) 
            degree *= -1; 
        plus[r1][c1] += degree;
        plus[r1][c2 + 1] -= degree;
        plus[r2 + 1][c1] -= degree;
        plus[r2 + 1][c2 + 1] += degree;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 1; j < M; ++j)
            plus[i][j] += plus[i][j - 1];

    for (int j = 0; j < M; ++j)
        for (int i = 1; i < N; ++i)
            plus[i][j] += plus[i - 1][j];

    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] + plus[i][j] > 0)
                answer++;

    return answer;
}
