#include <vector>
#include <iostream>

using namespace std;

long long SpendedTime(const vector<int> diffs, const vector<int> times, int level) {

    long long sum = 0;

    for (int i = 0; i < diffs.size(); ++i)
    {
        if (diffs[i] <= level)
        {
            sum += times[i];
        }
        else
        {
            sum += (long long)(diffs[i] - level) * (times[i] + times[i - 1]);
            sum += times[i];
        }
    }
    return sum;
}

int solution(const vector<int> diffs, const vector<int> times, long long limit) {

    if (SpendedTime(diffs, times, 1) <= limit) return 1;

    int low = 1;
    int high = 1e9;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        long long curTime = SpendedTime(diffs, times, mid);
        long long prevTime = SpendedTime(diffs, times, mid - 1);

        if (curTime <= limit && prevTime > limit)
        {
            return mid;
        }
        else if (curTime > limit)  //아직 제한시간 안에 못풀음
        {
            low = mid + 1; //레벨을 높여야 한다.
        }
        else
        {
            high = mid - 1;
        }
    }
}
