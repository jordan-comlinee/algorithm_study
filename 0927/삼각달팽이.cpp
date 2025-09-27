#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> Triangle(n);

    for (int i = 0; i < n; i++)
    {
        Triangle[i].resize(i + 1, 0);
    }

    int FinalNum = n * (n + 1) / 2;
    int PushNum = 1;
    int r = -1, c = 0;
    int MaxCount = n;
    int Count = 0;

    while (PushNum <= FinalNum)
    {
        Count = 0;
        while (1)
        {
            r++;
            Triangle[r][c] = PushNum;
            PushNum++;
            Count++;

            if (Count >= MaxCount)
            {
                MaxCount--;
                break;
            }
        }
        if (PushNum > FinalNum) break;

        Count = 0;
        while (1)
        {
            c++;
            Triangle[r][c] = PushNum;
            PushNum++;
            Count++;
            if (Count >= MaxCount)
            {
                MaxCount--;
                break;
            }
        }
        if (PushNum > FinalNum) break;

        Count = 0;
        while (1)
        {
            r--;
            c--;
            Triangle[r][c] = PushNum;
            PushNum++;
            Count++;
            if (Count >= MaxCount)
            {
                MaxCount--;
                break;
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            answer.push_back(Triangle[i][j]);
        }
    }
    return answer;
}
