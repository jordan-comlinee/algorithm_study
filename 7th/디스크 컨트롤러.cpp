#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int waitTime = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitq;
    for (auto job : jobs)
    {
        jq.push({ job[0], job[1] });
    }
    while (!jq.empty() || !waitq.empty())
    {
        while (!jq.empty() && jq.top().first <= time) {
            waitq.push({ jq.top().second, jq.top().first });
            jq.pop();
        }

        if (!waitq.empty()) {
            auto [duration, requestTime] = waitq.top(); waitq.pop();
            time += duration;
            waitTime += (time - requestTime);
        }
        else {
            time = jq.top().first;
        }


    }
    return waitTime / jobs.size();
}