#if 0
// seongho
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> u_find(100, -1);

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a[2] < b[2];
}

int find(int n)
{
    if(u_find[n] == -1)
        return n;
    u_find[n] = find(u_find[n]);
    return u_find[n];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), comp);
    for(const auto& t : costs)
    {
        int a_par = find(t[0]);
        int b_par = find(t[1]);
        if(a_par == b_par)
            continue;

        u_find[a_par] = b_par;
        answer+= t[2];
    }
    return answer;
}
#endif
#if 0
// jihoon
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& cost : costs)
    {
        int startP = cost[0], endP = cost[1], cost_ = cost[2];
        
        graph[startP].emplace_back(endP, cost_);
        graph[endP].emplace_back(startP, cost_);                
    }
    
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, 0});
    
    while(!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        
        if (visited[node])
        {
            continue;
        }
        visited[node] = true;
        answer += cost;
        
        for (const auto& [next, nextCost] : graph[node])
        {
            if (!visited[next])
            {
                pq.push({nextCost, next});
            }                
        }
    }
    
    return answer;
}
#endif
