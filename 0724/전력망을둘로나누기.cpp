#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <numeric>
using namespace std;

int check(vector<vector<int>>& wires, int m, int n)
{
    unordered_map<int, vector<int>> connect;
    for (int i = 0; i < wires.size(); ++i)
    {
        if (i == m) continue;
        connect[wires[i][0]].push_back(wires[i][1]);
        connect[wires[i][1]].push_back(wires[i][0]);
    }
    vector<int> net(n + 1, 0);
    queue<int> q;
    q.push(1);
    net[1] = 1;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto c : connect[cur])
        {
            if (net[c] != 1)
            {
                net[c] = 1;
                q.push(c);
            }
        }

    }
    int groupA = accumulate(net.begin(), net.end(), 0);
    int groupB = n - groupA;
    return abs(groupA - groupB);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT32_MAX;
    for (int i = 0; i < wires.size(); ++i)
    {
        answer = min(check(wires, i, n), answer);
    }
    return answer;
}