#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;


int check(int start, vector<vector<int>>& node,
    vector<int>& in, vector<int>& out, vector<bool>& visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    bool hasEnd = false;
    bool hasMerge = false;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (out[cur] == 0) hasEnd = true;
        if (in[cur] >= 2) hasMerge = true;

        for (int nxt : node[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    if (hasMerge) return 3;   // 8자
    if (hasEnd)   return 2;   // 막대
    return 1;                 // 도넛
}

// 생성한 정점의 번호, 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수
vector<int> solution(vector<vector<int>> edges) {
    int maxNode = 0;
    vector<int> answer(4, 0);
    for (auto edge : edges)
    {
        maxNode = max(maxNode, max(edge[0], edge[1]));
    }
    vector<int> in(maxNode + 1, 0), out(maxNode + 1, 0);

    for (auto edge : edges)
    {
        in[edge[1]]++;
        out[edge[0]]++;
    }

    for (int i = 1; i < maxNode + 1; ++i)
    {
        if (in[i] == 0 && out[i] >= 2)
        {
            answer[0] = i;
            break;
        }
    }

    vector<vector<int>> node(maxNode + 1);
    vector<bool> visited(maxNode + 1, false);
    vector<int> graphs;
    for (auto edge : edges)
    {
        if (edge[0] == answer[0]) graphs.push_back(edge[1]);
        node[edge[0]].push_back(edge[1]);
    }

    for (auto graph : graphs)
    {
        answer[check(graph, node, in, out, visited)]++;
    }

    return answer;
}