#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    // diff <= level -> time_cur 시간 사용
    // diff > level -> (diff-level)번 틀림, 틀릴때마다 time_cur 시간 사용 + time_prev(안틀림) + time_cur
    // limit 시간 내에 모두 해결하기 위한 level 최소값 구하기
    
    #if 0
    const int puzzleSize = diffs.size();
    int level = 1;    
    int totalTime = 0;
    
    while(limit > totalTime)
    {      
        totalTime = 0;
        int time_prev = 0;
        int time_cur = 0;
        
        for(int idx = 0; idx < puzzleSize; ++idx)
        {
            time_cur = times[idx];
            if(idx != 0)
            {
                time_prev = times[idx];
            }
            if(diffs[idx] <= level)
            {
                totalTime += time_cur;
            }
            else
            {
                totalTime += (time_prev + diffs[idx]) * (diffs[idx] - level);
            }
        }
        ++level;
    }    
    #endif
    
    #if 1
    
    const int puzzleSize = diffs.size();
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());
    answer = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        long long total = 0;

        for (int puzzleIdx = 0; puzzleIdx < puzzleSize; ++puzzleIdx)
        {
            if (diffs[puzzleIdx] <= mid)
            {
                total += times[puzzleIdx];
            }
            
            else
            {
                long long retryNum = diffs[puzzleIdx] - mid;
                long long time_prev;
                if(puzzleIdx != 0)
                {
                    time_prev = times[puzzleIdx - 1];
                }
                else
                {
                    time_prev = 0;
                }
                long long time_cur = times[puzzleIdx];
                total += (time_prev + time_cur) * retryNum + time_cur;
            }
            
            if(total > limit) 
            {
                break;
            }
        }

        if(total <= limit)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    #endif
    
    return answer;
}