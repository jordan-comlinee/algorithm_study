#include <string>
#include <vector>
#include <iostream>

using namespace std;

//n = 총 상자의 개수
//w = 가로 길이
//num = 꺼내려는 상자 번호

vector<vector<int>> Garage;

bool findNum(int NumtoFind, vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == NumtoFind)
        {
            return true;
        }
    }
    return false;
}

int findidx(int NumtoFind, vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == NumtoFind)
        {
            return i;
        }
    }
}

int solution(int n, int w, int num) {

    Garage.resize(w);
    int StartNum = 1;
    int CurrNum = 1;
    int CurrIdx = 0;

    while (1)
    {
        for (CurrNum = StartNum; CurrNum < StartNum + w; ++CurrNum)
        {
            if (CurrNum > n) break;
            CurrIdx = (CurrNum - 1) % w;
            Garage[CurrIdx].push_back(CurrNum);
        }
        StartNum = CurrNum;

        for (CurrNum = StartNum; CurrNum < StartNum + w; ++CurrNum)
        {
            if (CurrNum > n) break;
            CurrIdx = (w - 1) - ((CurrNum - 1) % w);
            Garage[CurrIdx].push_back(CurrNum);
        }
        StartNum = CurrNum;
        if (CurrNum > n) break;
    }

    for (int i = 0; i < Garage.size(); ++i)
    {
        if (findNum(num, Garage[i]) == true)
        {
            return Garage[i].size() - findidx(num, Garage[i]);
        }
    }
}