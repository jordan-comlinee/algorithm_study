#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int defendNum = 0;
    long long killEnemyNum = 0;
    
    for(const int& e : enemy)
    {
        pq.push(e);

        if(pq.size() > k)
        {
            killEnemyNum += pq.top();
            pq.pop();
        }

        if(killEnemyNum > n)
        {
            break;
        }
        ++answer;
    }
    
    return answer;
}