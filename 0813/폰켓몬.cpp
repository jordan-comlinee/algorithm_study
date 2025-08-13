#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> Monster(nums.begin(), nums.end());
    int pickSize = nums.size() / 2;
    int kindSize = (int)Monster.size();

    if (pickSize > kindSize)
    {
        return kindSize;
    }
    else
    {
        return pickSize;
    }
    return 0;
}