#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    queue<int> truck_wait;
    queue<int> bridge;

    int answer = 0;
    int total_weight = 0;

    for (int i = 0; i < truck_weights.size(); ++i) {
        truck_wait.push(truck_weights[i]);
    }

    for (int i = 0; i < bridge_length; ++i)
        bridge.push(0);

    while (!bridge.empty()) {
        answer++;

        total_weight -= bridge.front();
        bridge.pop();

        if (!truck_wait.empty()) {
            if (total_weight + truck_wait.front() <= weight) {

                bridge.push(truck_wait.front());
                total_weight += truck_wait.front();
                truck_wait.pop();
            }
            else {

                bridge.push(0);
            }
        }
    }
    return answer;
}
