#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


static vector<int> buildSums(const vector<int>& idxs, const vector<vector<int>>& dice) {
    vector<int> sums(1, 0);
    for (int id : idxs) {
        vector<int> next;
        for (int s : sums) {
            for (int face : dice[id]) {
                next.push_back(s + face);
            }
        }
        sums = next;
    }
    return sums;
}


int check(vector<int>& A, vector<int>& B, const vector<vector<int>>& dice)
{
    vector<int> sumA = buildSums(A, dice);
    vector<int> sumB = buildSums(B, dice);

    int win = 0;
    for (int a : sumA) {
        for (int b : sumB) {
            if (a > b) win++;
        }
    }
    return win;
}


vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int total = dice.size();
    int half = total / 2;
    int maxWin = 0;
    vector<bool> comb(total, false);
    for (int i = 0; i < half; ++i)
    {
        comb[i] = true;
    }
    do
    {
        vector<int> A;
        vector<int> B;
        for (int i = 0; i < total; ++i)
        {
            if (!comb[i])
            {
                B.push_back(i);
            }
            else
            {
                A.push_back(i);
            }
        }
        int curWin = check(A, B, dice);
        if (curWin > maxWin)
        {
            maxWin = curWin;
            answer = A;
        }
    } while (prev_permutation(comb.begin(), comb.end()));
    for (int i = 0; i < answer.size(); ++i)
    {
        answer[i]++;
    }

    return answer;
}