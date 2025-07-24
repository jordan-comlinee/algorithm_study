#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    const int edgeSize = edge.size();
    vector<vector<int>> graph(n + 1);
    
    for(const auto& e : edge)
    {
        int A = e[0];
        int B = e[1];
        
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);                
    }
    
    vector<int> distance(n + 1, 0);
    distance[1] = 1;
        
    queue<int> q;
    q.push(1);
    
    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        
        for(const int next : graph[curNode])
        {
            if(distance[next] == 0)
            {
                distance[next] = distance[curNode] + 1;
                q.push(next);
            }
        }
    }
    
    int biggestDistance = *max_element(distance.begin(), distance.end());
    
    for(int idx = 1; idx <= distance.size(); ++idx)
    {
        if(distance[idx] == biggestDistance)
        {
            ++answer;
        }
    }    
    return answer;
}