#include <string>
#include <vector>
#include <iostream>
using namespace std;

void getQuad(vector<vector<int>>& arr, int x, int y, int size, vector<int>& answer)
{
    bool isSame = true;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[x][y] != arr[x + i][y + j]) isSame = false;
        }
    }
    if (!isSame)
    {
        getQuad(arr, x, y, size / 2, answer);
        getQuad(arr, x + size / 2, y, size / 2, answer);
        getQuad(arr, x, y + size / 2, size / 2, answer);
        getQuad(arr, x + size / 2, y + size / 2, size / 2, answer);
    }
    else
    {
        answer[arr[x][y]]++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);

    getQuad(arr, 0, 0, arr.size(), answer);

    return answer;
}