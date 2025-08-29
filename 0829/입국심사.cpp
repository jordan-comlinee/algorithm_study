#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    
    long long left = 0;
    long long right = (long long)*max_element(times.begin(), times.end()) * n;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        
        long long cnt = 0;
        for(auto time : times)
        {
            cnt += mid / time;
        }
        
        if(cnt >= n)
        {
            answer = mid;
            right = mid -1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return answer;
}