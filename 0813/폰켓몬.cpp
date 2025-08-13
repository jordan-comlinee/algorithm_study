#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    // N 마리 포켓몬 중 N/2 가져가도 좋음
    // 종류에 따라 번호 붙여 구분
    // nums에 포ㅓ켓몬 종류 번호 담긴 배열
    // 가장 많은 종류의 포켓몬 선택하는 방법
    
    unordered_set<int> Arr(nums.begin(), nums.end());
    int maxPick = nums.size() / 2;
    
    // 6C3 -> 6*5*4 / 3*2*1 = 20 -> 10 겹치는거 333, 22 -> 10 - 5 - 1 = 
    // 4C2 -> 4*3 / 2*1 = 6 -> 3, 겹치는거 33  -> 3 - 1 = 2
    
    return min(maxPick, (int)Arr.size());
}