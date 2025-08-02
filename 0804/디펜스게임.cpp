#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    if (enemy.size() <= k) return enemy.size();
    priority_queue<int, vector<int>, greater<int>> pq(enemy.begin(), enemy.begin() + k);
    while (k + answer < enemy.size())
    {
        if (!pq.empty() && pq.top() < enemy[k + answer])
        {
            n -= pq.top();
            pq.pop();
            pq.push(enemy[k + answer]);
        }
        else
        {
            n -= enemy[k + answer];
        }
        if (n < 0) break;
        answer++;
    }
    return answer + k;
}