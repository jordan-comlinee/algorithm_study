#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> PQ;

int solution(int n, int k, vector<int> enemy) {

    int stage = 0;

    for (stage = 0; stage < enemy.size(); ++stage)
    {
        if (n >= enemy[stage])
        {
            n -= enemy[stage];
            PQ.push(enemy[stage]);
        }
        else
        {
            if (k == 0) break;

            if (!PQ.empty() && (PQ.top() >= enemy[stage]))
            {
                n += PQ.top();
                PQ.pop();

                n -= enemy[stage];
                PQ.push(enemy[stage]);
            }

            --k;
        }
    }

    return stage;
}