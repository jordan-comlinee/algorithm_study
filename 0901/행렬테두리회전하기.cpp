#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int rotate(vector<vector<int>>& board, pair<int, int>& start, pair<int, int>& end)
{
    int top = start.first, left = start.second;
    int bottom = end.first, right = end.second;

    vector<vector<int>> tmp_board = board;

    int mn = INT32_MAX;

    for (int y = left + 1; y <= right; ++y) {
        board[top][y] = tmp_board[top][y - 1];
        mn = min(mn, board[top][y]);
    }
    for (int y = left; y < right; ++y) {
        board[bottom][y] = tmp_board[bottom][y + 1];
        mn = min(mn, board[bottom][y]);
    }
    for (int x = top; x < bottom; ++x) {
        board[x][left] = tmp_board[x + 1][left];
        mn = min(mn, board[x][left]);
    }
    for (int x = top + 1; x <= bottom; ++x) {
        board[x][right] = tmp_board[x - 1][right];
        mn = min(mn, board[x][right]);
    }
    return mn;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns, 0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            board[i][j] = i * columns + j + 1;
        }
    }

    for (auto query : queries)
    {
        pair<int, int> start = { query[0] - 1, query[1] - 1 };
        pair<int, int> end = { query[2] - 1, query[3] - 1 };
        answer.push_back(rotate(board, start, end));
    }

    return answer;
}