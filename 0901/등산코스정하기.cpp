#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 간선 정보
struct Edge {
    int to, weight;
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    vector<vector<Edge>> graph(n + 1);

    // 정답을 구하기 위해 정렬
    sort(summits.begin(), summits.end());

    // 그래프 정보 초기화 (양방향)
    for (vector<int> r : paths) {
        int from = r[0];
        int to = r[1];
        int weight = r[2];
        graph[from].push_back({ to, weight });
        graph[to].push_back({ from, weight });
    }

    // summits의 ID를 빠르게 검색하기위한 set
    unordered_set<int> summitIds;
    for (int i = 0; i < summits.size(); ++i)
        summitIds.insert(summits[i]);

    // gates ID를 빠르게 검색하기위한 set
    unordered_set<int> gateIds;
    for (int i = 0; i < gates.size(); ++i)
        gateIds.insert(gates[i]);

    vector<int> dp(summits.size(), INT_MAX);
    for (int i = 0; i < gates.size(); ++i)
    {
        vector<int> dist(n + 1, INT_MAX);
        vector<int> maxValue(n + 1, INT_MAX);

        // 우선순위 큐를 이용한 다익스트라 알고리즘
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[gates[i]] = 0; // 시작 노드의 거리는 0
        maxValue[gates[i]] = 0;
        pq.push({ 0, gates[i] }); // {거리, 노드} 쌍을 우선순위 큐에 삽입

        while (!pq.empty()) {
            int current_distance = pq.top().first;
            int current_node = pq.top().second;
            pq.pop();

            // 현재 노드에서 갈 수 있는 모든 노드들에 대해 최단 거리 갱신
            for (Edge& e : graph[current_node]) {
                int next_node = e.to;
                int weight = e.weight;

                // gate로의 이동은 금지
                if (gateIds.find(next_node) != gateIds.end())
                    continue;

                // 가중치가 낮다면, 갱신
                if (dist[next_node] > weight) {
                    dist[next_node] = weight; // 해당 노드의 weight를 기록
                    maxValue[next_node] = max(maxValue[current_node], dist[next_node]); // 해당 노드까지의 최대 피로도를 계산
                    pq.push({ dist[next_node], next_node });
                }
            }

            // 만약, 산봉우리에 도착하였다면 더 이상 계산할 필요가 없기에 while문 리턴
            if (summitIds.find(current_node) != summitIds.end())
                break;
        }

        // 정답을 구할 dp에 모든 값을 최소값으로 갱신
        for (int j = 0; j < summits.size(); ++j)
            dp[j] = min(dp[j], maxValue[summits[j]]);
    }

    // 역방향으로 검사하여 최소값을 정답에 저장(정렬 필요)
    vector<int> answer{ INT_MAX, INT_MAX };
    for (int i = summits.size() - 1; i >= 0; --i)
        if (answer[1] >= dp[i])
            answer = { summits[i], dp[i] };

    return answer;
}