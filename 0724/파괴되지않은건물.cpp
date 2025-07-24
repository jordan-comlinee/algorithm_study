#include <vector>
using namespace std;

#define ENEMY_ATTACK 1
#define TEAM_HEAL 2

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    //È¿À²¼º Å»¶ô

    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < skill.size(); ++i)
    {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];

        int value;
        if (type == ENEMY_ATTACK)
        {
            value = -degree;
        }
        else
        {
            value = degree;
        }

        for (int r = r1; r <= r2; ++r)
        {
            for (int c = c1; c <= c2; ++c)
            {
                board[r][c] += value;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] > 0)
            {
                ++answer;
            }
        }
    }
    return answer;
}
