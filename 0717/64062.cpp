#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int begin = *min_element(stones.begin(), stones.end());
    int end = *max_element(stones.begin(), stones.end());
    int mid;
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        int skipCnt = 0;
        int maxSkipCnt = 0;
        vector<int> tmp(stones);
        for (int i = 0; i < tmp.size(); ++i)
        {
            tmp[i] -= mid;
            if (tmp[i] < 0) skipCnt++;
            else skipCnt = 0;
            maxSkipCnt = max(maxSkipCnt, skipCnt);
        }
        if (maxSkipCnt < k)
        {
            answer = max(answer, mid);
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return answer;
}