#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solvePuzzle(int prevTime, int curTime, int diff, int level)
{
    return (curTime + prevTime) * (diff - level) + curTime;
}

long long getTotal(vector<int>& diffs, vector<int>& times, long long& limit, int min)
{
    long long total = 0;
    for (int i = 0; i < diffs.size(); ++i)
    {
        if (min >= diffs[i])
        {
            total += times[i];
        }
        else
        {
            total += solvePuzzle(i < 1 ? times[0] : times[i - 1], times[i], diffs[i], min);
        }
        if (total > limit)
            return total;
    }
    return total;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int min = 1;
    int max = *max_element(diffs.begin(), diffs.end());
    int mid;
    while (min <= max)
    {
        mid = (min + max) / 2;
        long long totalTime = getTotal(diffs, times, limit, mid);
        if (totalTime > limit)
            min = mid + 1;
        else
            max = mid - 1;
    }
    answer = min;
    return answer;
}