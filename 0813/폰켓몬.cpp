#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;
    for(const auto& t : nums)
    {
        s.insert(t);
    }
    answer = s.size();
    if(answer > nums.size()/2)
        answer = nums.size()/2;
    return answer;
}
