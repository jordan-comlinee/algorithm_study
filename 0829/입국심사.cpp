#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> times) {
    auto MAX = max_element(times.begin(), times.end());
    long long answer = 0;
    long long first = 1, last = (long long)(*MAX)*n;
    long long mid = (first + last)/2;
    while(first<=last)
    {
        mid = (first + last)/2;
        long long cnt = 0;
        for(const auto& t : times)
        {
            cnt+= (mid/t);
        }

        if(cnt >= n)
        {
            answer = mid;
            last = mid - 1;
        }
        else
        {
            first = mid+1;
        }
        
    }

    return answer;
}
