#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, int>> graph[100]; // graph[from] = {to, cost}
bool visited[100];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (auto& cost : costs) {
        int a = cost[0], b = cost[1], c = cost[2];
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, 0 }); // {cost, node}

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (visited[cur.second]) continue;
        visited[cur.second] = true;
        answer += cur.first;

        for (auto& [next, next_cost] : graph[cur.second]) {
            if (!visited[next]) {
                pq.push({ next_cost, next });
            }
        }
    }

    return answer;
}
