#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(int x, int y, const vector<vector<int>>& board)
{
    int maxLen = 0;
    int N = board.size();
    int M = board[0].size();

    for (int len = 1; x + len <= N && y + len <= M; ++len)
    {
        bool allOne = true;
        for (int i = x; i < x + len; ++i)
        {
            for (int j = y; j < y + len; ++j)
            {
                if (board[i][j] == 0)
                {
                    allOne = false;
                    break;
                }
            }
            if (!allOne) break;
        }
        if (allOne)
            maxLen = len;
        else
            break;
    }

    return maxLen;
}

int solution(vector<vector<int>> board)
{
    int maxLength = 0;
    int r = board.size();
    int c = board[0].size();

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] == 1)
            {
                maxLength = max(check(i, j, board), maxLength);
            }
        }
    }

    return maxLength * maxLength;
}
