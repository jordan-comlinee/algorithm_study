#include <string>
#include <vector>

using namespace std;

long long MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {

    vector<vector<int>> memo;
    memo.resize(m);

    for (int i = 0; i < m; ++i)
    {
        memo[i].resize(n);
    }

    for (vector<int> p : puddles)
    {
        memo[p[0] - 1][p[1] - 1] = -1;
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (memo[i][j] == -1)
            {
                continue;
            }

            if (i == 0 && j == 0)
            {
                memo[i][j] = 1;
                continue;
            }

            long long up = 0;
            long long left = 0;

            if (i - 1 >= 0 && memo[i - 1][j] != -1)
            {
                up = memo[i - 1][j];
            }
            if (j - 1 >= 0 && memo[i][j - 1] != -1)
            {
                left = memo[i][j - 1];
            }

            memo[i][j] = (int)((up + left) % MOD);
        }
    }

    int answer = memo[m - 1][n - 1] % MOD;
    return answer;
}