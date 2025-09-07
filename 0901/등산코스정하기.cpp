#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <algorithm>
using namespace std;

// ���� ����
struct Edge {
    int to, weight;
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    vector<vector<Edge>> graph(n + 1);

    // ������ ���ϱ� ���� ����
    sort(summits.begin(), summits.end());

    // �׷��� ���� �ʱ�ȭ (�����)
    for (vector<int> r : paths) {
        int from = r[0];
        int to = r[1];
        int weight = r[2];
        graph[from].push_back({ to, weight });
        graph[to].push_back({ from, weight });
    }

    // summits�� ID�� ������ �˻��ϱ����� set
    unordered_set<int> summitIds;
    for (int i = 0; i < summits.size(); ++i)
        summitIds.insert(summits[i]);

    // gates ID�� ������ �˻��ϱ����� set
    unordered_set<int> gateIds;
    for (int i = 0; i < gates.size(); ++i)
        gateIds.insert(gates[i]);

    vector<int> dp(summits.size(), INT_MAX);
    for (int i = 0; i < gates.size(); ++i)
    {
        vector<int> dist(n + 1, INT_MAX);
        vector<int> maxValue(n + 1, INT_MAX);

        // �켱���� ť�� �̿��� ���ͽ�Ʈ�� �˰���
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[gates[i]] = 0; // ���� ����� �Ÿ��� 0
        maxValue[gates[i]] = 0;
        pq.push({ 0, gates[i] }); // {�Ÿ�, ���} ���� �켱���� ť�� ����

        while (!pq.empty()) {
            int current_distance = pq.top().first;
            int current_node = pq.top().second;
            pq.pop();

            // ���� ��忡�� �� �� �ִ� ��� ���鿡 ���� �ִ� �Ÿ� ����
            for (Edge& e : graph[current_node]) {
                int next_node = e.to;
                int weight = e.weight;

                // gate���� �̵��� ����
                if (gateIds.find(next_node) != gateIds.end())
                    continue;

                // ����ġ�� ���ٸ�, ����
                if (dist[next_node] > weight) {
                    dist[next_node] = weight; // �ش� ����� weight�� ���
                    maxValue[next_node] = max(maxValue[current_node], dist[next_node]); // �ش� �������� �ִ� �Ƿε��� ���
                    pq.push({ dist[next_node], next_node });
                }
            }

            // ����, ����츮�� �����Ͽ��ٸ� �� �̻� ����� �ʿ䰡 ���⿡ while�� ����
            if (summitIds.find(current_node) != summitIds.end())
                break;
        }

        // ������ ���� dp�� ��� ���� �ּҰ����� ����
        for (int j = 0; j < summits.size(); ++j)
            dp[j] = min(dp[j], maxValue[summits[j]]);
    }

    // ���������� �˻��Ͽ� �ּҰ��� ���信 ����(���� �ʿ�)
    vector<int> answer{ INT_MAX, INT_MAX };
    for (int i = summits.size() - 1; i >= 0; --i)
        if (answer[1] >= dp[i])
            answer = { summits[i], dp[i] };

    return answer;
}