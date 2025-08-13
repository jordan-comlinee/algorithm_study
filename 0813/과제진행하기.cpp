#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int toMinute(const string& time)
{
    return (time[0] - '0') * 600 +
        (time[1] - '0') * 60 +
        (time[3] - '0') * 10 +
        (time[4] - '0');
}

bool Compare(vector<string> a, vector<string> b)
{
    return toMinute(a[1]) < toMinute(b[1]);
}

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    vector<pair<string, int>> stopStack;

    sort(plans.begin(), plans.end(), Compare);

    int nowTime = toMinute(plans[0][1]);
    stopStack.push_back({ plans[0][0], stoi(plans[0][2]) });

    for (int i = 1; i < plans.size(); ++i)
    {
        int nextTime = toMinute(plans[i][1]);
        int remainTime = nextTime - nowTime;

        while (remainTime > 0 && !stopStack.empty())
        {
            pair<string, int> current = stopStack.back();
            if (current.second <= remainTime)
            {
                remainTime -= current.second;
                nowTime += current.second;
                answer.push_back(current.first);
                stopStack.pop_back();
            }
            else
            {
                current.second -= remainTime;
                nowTime += remainTime;
                remainTime = 0;
            }
        }

        stopStack.push_back({ plans[i][0], stoi(plans[i][2]) });
        nowTime = nextTime;
    }

    while (!stopStack.empty())
    {
        answer.push_back(stopStack.back().first);
        stopStack.pop_back();
    }

    return answer;
}