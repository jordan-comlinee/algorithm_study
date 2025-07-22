#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

// 번호, 요청시각, 소요시간을 담아줄 Node
typedef struct _node
{
    int num;
    int req_time;
    int dur_time;
    
    // 힙 우선순위 설정
    friend bool operator<(_node const& lhs, _node const& rhs)
    {
        if(lhs.dur_time != rhs.dur_time)
            return lhs.dur_time > rhs.dur_time;
        else if(lhs.req_time != rhs.req_time)
            return lhs.req_time > rhs.req_time;
        else
            return lhs.num > rhs.num;
    }
} Node;

int solution(vector<vector<int>> jobs) {
    vector<vector<int>> j;
    for(int i = 0; i<jobs.size(); i++)
    {
        j.push_back({i, jobs[i][0], jobs[i][1]});
    }
    // 요청시간 빠른 순, 작업 시간 짧은 순으로 정렬
    sort(j.begin(), j.end(), [](vector<int>& a, vector<int>& b){
        if(a[1]!=b[1])
            return a[1] < b[1];
        else
            return a[2] < b[2];
    });

    priority_queue<Node> pq;
    int idx = 0;
    int work_until = -1;
    int answer = 0;
    
    while(true)
    {
        // 현재 시각보다 요청 시간이 빠르거나 같은거 다 힙에 삽입
        while(idx < j.size() && work_until >= j[idx][1])
        {
            pq.push({j[idx][0], j[idx][1], j[idx][2]});
            idx++;
        }
        
        // 1. 힙은 비어있는데 처리해야할 job은 남아있는 경우 최우선 일 처리
        if(pq.empty() && idx < j.size())
        {
            answer+=j[idx][2];
            work_until = j[idx][1] + j[idx][2];
            idx++;
        }
        
        // 2. 힙이 비어있지 않은 경우 top 업무 처리 
        else if(!pq.empty())
        {
            Node temp = pq.top();
            pq.pop();
            work_until+=temp.dur_time;
            answer+=(work_until - temp.req_time);
            
        }
        
        // 3. 힙이 비어있고 남아있는 업무도 없을 경우 반복문 탈출
        else
            break;
    }
    
    answer = answer/jobs.size();
    
    
    return answer;
}