#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else if (a.second == b.second)
        return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages) {

    vector<pair<int, double>> failure;
    vector<int> answer;

    for (int CurrStage = 1; CurrStage <= N; ++CurrStage)
    {
        int CurrAttempt = 0;
        int CurrFail = 0;
        double failurePercent = 0.0;

        for (int j = 0; j < stages.size(); ++j)
        {
            if (stages[j] >= CurrStage)
                CurrAttempt++;
            if (stages[j] == CurrStage)
                CurrFail++;
        }
        if (CurrAttempt != 0) {
            failurePercent = (double)CurrFail / (double)CurrAttempt;
        }
        failure.push_back(make_pair(CurrStage, failurePercent));
    }
    sort(failure.begin(), failure.end(), compare);

    for (int i = 0; i < failure.size(); ++i)
    {
        answer.push_back(failure[i].first);
    }
    return answer;
}