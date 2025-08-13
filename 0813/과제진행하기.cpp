#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int hTm(const string& playtime)
{
    const int hour = stoi(playtime.substr(0, 2));
    const int min = stoi(playtime.substr(3, 2));
    return hour * 60 + min;
}

struct Paused
{
    string name;
    int lastTime;
    int order; // 멈춘 순번(클수록 더 최근)
};

struct pqSorting
{
    bool operator()(const Paused& a, const Paused& b) const
    {
        return a.order < b.order;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    const int plansSize = plans.size();
    sort(plans.begin(), plans.end(), [](const vector<string>& planA, const vector<string>& planB)
         {
             return hTm(planA[1]) < hTm(planB[1]);
         });
    
    int curTime = 0;
    priority_queue<Paused, vector<Paused>, pqSorting> pq;
    // pq.push(plans[0]);
    int seq = 0;
    for(int idx = 0; idx < plansSize - 1; ++idx)
    {
        const string& name = plans[idx][0];
        const int start = hTm(plans[idx][1]);
        int lastPlayTime = stoi(plans[idx][2]);

        const int nextStart = hTm(plans[idx + 1][1]);
        int gap = nextStart - start;
        
        if(lastPlayTime <= gap)  // 다음꺼 시작 전에 끝냄
        {
            answer.push_back(name);
            gap -= lastPlayTime;
            
            while (gap > 0 && !pq.empty())
            {
                auto cur = pq.top();
                pq.pop();
                
                if(cur.lastTime <= gap)   // gap 동안 끝낼 수 있음
                {
                    gap -= cur.lastTime;
                    answer.push_back(cur.name);
                }
                else // 다 못 끝내고 또 멈출거
                {                    
                    cur.lastTime -= gap;
                    cur.order = ++seq;
                    pq.push(cur);
                    gap = 0;
                }
            }
        }
        else
        {
            pq.push(Paused{name, lastPlayTime - gap, ++seq});
        }
    }
    
    answer.push_back(plans.back()[0]);

    while(!pq.empty())
    {
        answer.push_back(pq.top().name);
        pq.pop();
    }
    
    return answer;
}