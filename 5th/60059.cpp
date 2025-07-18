#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool check(vector<vector<int>>& keyLocation, vector<vector<int>>& lock, int M)
{
    int N = lock.size();
    for (int i = M - 1; i < M - 1 + N; ++i)
    {
        for (int j = M - 1; j < M - 1 + N; ++j)
        {
            int lockI = i - (M - 1);
            int lockJ = j - (M - 1);
            if (lock[lockI][lockJ] + keyLocation[i][j] != 1) return false;
        }
    }
    return true;
}

void rotate(vector<vector<int>>& key)
{
    int M = key.size();
    vector<vector<int>> tmp(M, vector<int>(M));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            tmp[i][j] = key[M - j - 1][i];
        }
    }
    key = tmp;
}

bool putKey(vector<vector<int>>& key, vector<vector<int>>& lock)
{
    int N = lock.size();
    int M = key.size();
    int boardSize = N + 2 * (M - 1);
    for (int i = 0; i <= boardSize - M; ++i)
    {
        for (int j = 0; j <= boardSize - M; ++j)
        {

            vector<vector<int>> board(boardSize, vector<int>(boardSize));

            for (int k = 0; k < M; ++k)
            {
                for (int l = 0; l < M; ++l)
                {
                    board[i + k][j + l] = key[k][l];
                }
            }
            if (check(board, lock, M)) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for (int i = 0; i < 4; ++i)
    {
        if (putKey(key, lock)) return true;
        rotate(key);

    }
    return false;
}
