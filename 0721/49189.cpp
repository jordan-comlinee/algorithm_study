#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> nodes(edge.size() + 1);
    for (auto e : edge)
    {
        nodes[e[0]].emplace_back(e[1]);
        nodes[e[1]].emplace_back(e[0]);
    }
    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto n : nodes[cur])
        {
            if (dist[n] == -1)
            {
                dist[n] = dist[cur] + 1;
                q.push(n);
            }
        }


    }

    int max = *max_element(dist.begin(), dist.end());
    for (auto d : dist)
    {
        if (d == max) answer++;
    }
    return answer;
}