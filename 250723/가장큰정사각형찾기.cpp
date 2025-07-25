#include <iostream>
#include<vector>
using namespace std;

bool check_valid(int x, int y, int size, vector<vector<int>> board)
{
    int row = board.size();
    int col = board[0].size();

    if (x + size > row || y + size > col)
    {
        return false;
    }
    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (board[i][j] != 1) return false;
        }
    }
    return true;
}

int MaxSqLen(int x, int y, int size, vector<vector<int>> board)
{
    if (!check_valid(x, y, size, board))
        return size - 1;
    else
        return  MaxSqLen(x, y, size + 1, board);
}

int solution(vector<vector<int>> board)
{
    int maxlen = 0;

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (maxlen < MaxSqLen(i, j, 1, board))
            {
                maxlen = MaxSqLen(i, j, 1, board);
            }
        }
    }
    return maxlen * maxlen;
}