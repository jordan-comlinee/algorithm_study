#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct task
{
    int taskNumber;
    int requestTime;
    int necessaryTime;
    int realEndTime;
};

struct sortTasks
{
    bool operator()(const task &a, const task &b) const
    {
        if(a.necessaryTime != b.necessaryTime)
        {
            return a.necessaryTime > b.necessaryTime;
        }
        
        if (a.requestTime != b.requestTime)
        {
            return a.requestTime > b.requestTime;
        }
        return a.taskNumber > b.taskNumber;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // 대기 큐: 작업의 번호/작업의 요청 시각/작업의 소요 시간
    // 작업의 소요시간 짧은거 > 작업의 요청 시각 빠른거 > 작업의 번호 작은거
    // 평균 정수부분 retrun
    // 큐 비어있으면 바로 다음 작업 ㅅ자ㅣㄱ
    
    const int jobsNum = jobs.size();
    // vector<vector<int>> start2end(jobsNum, vector<int>(2, 0));
    vector<task> tasks;
    
    for(int i = 0; i < jobsNum; ++i)
    {
        task t;
        t.taskNumber = i;
        t.requestTime = jobs[i][0];
        t.necessaryTime = jobs[i][1];
        t.realEndTime = 0;
        tasks.push_back(t);
    }
    
    sort(tasks.begin(), tasks.end(), [](auto &a, auto &b){
        return a.requestTime < b.requestTime;
    });
    
    priority_queue<task, vector<task>, sortTasks> pq;

    int curTime = 0;
    int idx = 0;
    int totalTime = 0;

    while(idx < jobsNum || !pq.empty())
    {
        while(idx < jobsNum && tasks[idx].requestTime <= curTime)
        {
            pq.push(tasks[idx]);
            ++idx;
        }

        if(pq.empty())
        {
            curTime = tasks[idx].requestTime;
            continue;
        }

        task t = pq.top();
        pq.pop();
        
        curTime += t.necessaryTime;
        
        t.realEndTime = curTime;

        totalTime += (t.realEndTime - t.requestTime);
    }

    answer = totalTime / jobsNum;
    
    return answer;
}
