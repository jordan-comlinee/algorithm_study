#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer=1;
    
    const int sSize = s.size();
    const int mid = sSize / 2;
    
//     if(sSize % 2)   // 홀수 길이
//     {
                     
//     }
//     else
//     {
        
//     }
    
    // for(int center = mid; center < sSize; ++center)
    for(int center = 0; center < sSize; ++center)
    {
        int left = center;
        int right = center;
        for(; left >= 0 && right < sSize && s[left] == s[right]; --left, ++right)
        {
            answer = max(answer, right - left + 1);
        }
        
        left = center;
        right = center + 1;
        for(; left >= 0 && right < sSize && s[left] == s[right]; --left, ++right)
        {
            answer = max(answer, right - left + 1);
        }
    }   
    
    return answer;
}