#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<int> fail(N + 2, 0);
    vector<pair<double, int>> failPercent(N, { 0.0, 0 });
    int players = stages.size();
    for (int i = 0; i < stages.size(); ++i)
    {
        fail[stages[i]]++;
    }
    for (int i = 0; i < N; ++i)
    {
        failPercent[i].second = i + 1;
        if (players == 0) failPercent[i].first = 0.0;
        else
        {
            failPercent[i].first = (double)((double)fail[i + 1] / (double)players);
            players -= fail[i + 1];

        }
    }
    sort(failPercent.begin(), failPercent.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
        });
    for (int i = 0; i < N; ++i)
    {
        answer[i] = failPercent[i].second;
    }
    return answer;
}