#if 0
// soyoung
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
#endif
#if 0
// jihoon
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    // 다리를 건너는 트럭을 처리하기 위한 큐 (데이터{삽입 시간, 무게})
    queue<pair<int, int>> bridge;
    // 다리 위를 지나고있는 트럭의 무게 합
    int truck_weight_on_bridge = 0;
    // 다리 위를 지나고있는 트럭의 수
    int truck_count_on_bridge = 0;
    
    int time = 0;
    // 건너야하는 트럭을 가리키는 인덱스
    int idx = 0;
    
    // 반복문 (다리 위에 아무 것도 없을 때 반복문 종료)
    while(true)
    {
        // 시간 경과
        time++;
        
        // 다리가 비어있지 않다면 최선두 트럭 도달 여부 확인 및 pop
        if(!bridge.empty())
        {
            if(time - bridge.front().first == bridge_length)
            {
                truck_weight_on_bridge -= bridge.front().second;
                bridge.pop();
                truck_count_on_bridge--;
            }
        }
        
        // 남은 트럭이 있는지 여부, 다리에 다음 트럭 무게 지탱 가능 여부, 트럭의 개수 추가 가능 여부 판단 후 가능하다면 push
        if(idx < truck_weights.size() && truck_weight_on_bridge + truck_weights[idx] <= weight && truck_count_on_bridge < bridge_length)
        {
            bridge.push({time, truck_weights[idx]});
            truck_weight_on_bridge += truck_weights[idx];
            truck_count_on_bridge++;
            idx++;
        }
        if(bridge.empty())
            break;
    }
    return time;
}
# endif