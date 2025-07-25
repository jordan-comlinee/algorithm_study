#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

int bfs(const int wiresNum, const vector<vector<int>>& tree, vector<bool>& visited)
{
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int wierNum = 1;

    while(!q.empty())
    {
        int c = q.front();
        q.pop();

        for(const int& next : tree[c])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
                ++wierNum;
            }
        }
    }

    return wierNum;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    const int wiresNum = n;
    
    for(int i = 0; i < wires.size(); ++i)
    {
        vector<vector<int>> tree(n + 1);
        vector<bool> visited(n + 1, false);

        for(int j = 0; j < wires.size(); ++j)
        {
            if(i == j)
            {
                continue;
            }
            
            tree[wires[j][0]].emplace_back(wires[j][1]);
            tree[wires[j][1]].emplace_back(wires[j][0]);
        }
        
        int wireNum1 = bfs(wiresNum, tree, visited);
        int wireNum2 = n - wireNum1;
        
        answer = min(answer, abs(wireNum1 - wireNum2));
    }    
    
    return answer;
}