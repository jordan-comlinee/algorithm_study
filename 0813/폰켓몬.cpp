#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> set;
    for (auto num : nums)
    {
        set.insert(num);
    }
    return nums.size() / 2 < set.size() ? nums.size() / 2 : set.size();
}