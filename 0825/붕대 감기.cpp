#include <string>
#include <vector>
#include <iostream>
using namespace std;
// bandage는 [시전 시간, 초당 회복량, 추가 회복량]
// attacks[i]는 [공격 시간, 피해량] 형태의 길이가 2인 정수 배열
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;

    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    int prev = 0;
    for (auto attack : attacks)
    {
        int time = attack[0] - prev - 1;
        int heal = x * time + (time / t) * y;
        answer = answer + heal >= health ? health : answer + heal;
        answer -= attack[1];
        if (answer <= 0) return -1;
        prev = attack[0];
    }
    return answer;
}