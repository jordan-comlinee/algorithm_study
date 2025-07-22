#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int bridge_weight = 0;
    deque<int> trucks(truck_weights.begin(), truck_weights.end());
    deque<int> bridge(bridge_length, 0);
    while (!trucks.empty() || bridge_weight > 0)
    {
        answer++;
        bridge_weight -= bridge.front();
        bridge.pop_front();
        if (!trucks.empty() && bridge_weight + trucks.front() <= weight)
        {
            bridge.push_back(trucks.front());
            bridge_weight += trucks.front();
            trucks.pop_front();
        }
        else
        {
            bridge.push_back(0);
        }

    }
    return answer;
}