#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> nodes;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 1;

    for (int v : nodes[u]) {
        if (!visited[v]) {
            dfs(v);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    nodes.assign(n + 1, {});
    dp.assign(n + 1, vector<int>(2, 0));
    visited.assign(n + 1, false);

    for (auto& light : lighthouse) {
        nodes[light[0]].push_back(light[1]);
        nodes[light[1]].push_back(light[0]);
    }

    dfs(1);

    return min(dp[1][0], dp[1][1]);
}