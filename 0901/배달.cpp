#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> nodes(N + 1);
    vector<int> dists(N + 1, INT32_MAX);
    for (auto r : road)
    {
        int st = r[0], en = r[1], dist = r[2];
        nodes[st].push_back({ en, dist });
        nodes[en].push_back({ st, dist });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dists[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();
        if (curDist > dists[cur]) continue;
        for (auto [next, nextDist] : nodes[cur])
        {
            if (dists[next] < curDist + nextDist) continue;
            dists[next] = curDist + nextDist;
            pq.push({ dists[next], next });
        }
    }

    for (auto d : dists)
    {
        if (d <= K) ++answer;
    }

    return answer;
}