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