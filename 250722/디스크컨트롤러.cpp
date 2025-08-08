#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Task {
    int TakeTime;
    int RequestTime;
    int WorkNum;
} Task;

bool compare(Task a, Task b)
{
    if (a.TakeTime != b.TakeTime)
        return a.TakeTime < b.TakeTime;
    else if (a.RequestTime != b.RequestTime)
        return a.RequestTime < b.RequestTime;
    else
        return a.WorkNum < b.WorkNum;
}

bool compareRequestTime(Task a, Task b)
{
    return a.RequestTime < b.RequestTime;
}

int solution(vector<vector<int>> jobs) {
    vector<Task> jobList;
    for (int i = 0; i < jobs.size(); ++i)
        jobList.push_back((Task) { jobs[i][1], jobs[i][0], i });

    sort(jobList.begin(), jobList.end(), compareRequestTime);

    int time = 0;
    int idx = 0;
    int total = 0;
    int done = 0;

    vector<Task> wait;

    while (done < jobs.size()) {
        while (idx < jobList.size() && jobList[idx].RequestTime <= time) {
            wait.push_back(jobList[idx]);
            idx++;
        }

        if (wait.empty()) {
            time = jobList[idx].RequestTime;
            continue;
        }

        int minIdx = 0;
        for (int i = 1; i < wait.size(); ++i)
            if (compare(wait[i], wait[minIdx]))
                minIdx = i;

        Task now = wait[minIdx];
        wait.erase(wait.begin() + minIdx);

        time += now.TakeTime;
        total += time - now.RequestTime;
        done++;
    }

    return total / jobs.size();
}
