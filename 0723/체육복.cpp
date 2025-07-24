#if 0
// soyoung
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> attendees(n + 2, 0);
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 1; i < n + 1; ++i)
    {
        attendees[i] = 1;
    }
    for (auto l : lost)
    {
        attendees[l] = 0;
    }
    for (auto r : reserve)
    {
        attendees[r]++;
    }
    for (auto l : lost)
    {
        if (attendees[l] == 0)
        {
            if (attendees[l - 1] > 1)
            {
                attendees[l - 1]--;
                attendees[l]++;
            }
            else if (attendees[l + 1] > 1)
            {
                attendees[l + 1]--;
                attendees[l]++;
            }
        }

    }
    for (auto a : attendees)
    {
        if (a > 0) answer++;
    }
    return answer;
}
#endif
#if 0
// seongho
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    vector<int> arr(n+2, 1);
    arr[0] = 0, arr[n+1] = 0;
    for(const auto& t :reserve)
        arr[t]++;
    for(const auto& t : lost)
        arr[t]--;
    
    for(int i = 1; i<=n; i++)
    {
        if(arr[i] > 0)
            continue;
        if(arr[i-1] == 2)
        {
            arr[i-1] = 1;
            arr[i] = 1;
        }
        else if(arr[i+1] == 2)
        {
            arr[i+1] = 1;
            arr[i] = 1;
        }
        else
        {
            
            answer--;
           continue;
        }
     
    }

    return answer;
}
#endif

#if 0
// jihoon
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int lostNum = lost.size();
    int reserveNum = reserve.size();
    
    sort(lost.begin(), lost.end(), [](const int& a, const int& b)
         {
             return a < b;
         });
    sort(reserve.begin(), reserve.end(), [](const int& a, const int& b)
         {
             return a < b;
         });
    
    for(int i = 0; i < reserve.size(); ++i)
    {
        for(int j = 0; j < lost.size(); ++j)
        {
            if(reserve[i] == lost[j])
            {
                reserve.erase(reserve.begin() + i);
                lost.erase(lost.begin() + j);
                --i;
                break;
            }
        }
    }

    answer = n - lost.size();
    
    for(const int& l : lost)
    {
        int idx = 0;
        for(const int& r : reserve)
        {
            if(((r + 1) == l) || ((r - 1) == l))
            {
                reserve.erase(reserve.begin() + idx);
                ++answer;
                break;
            }
            ++idx;
        }
    }
    
    return answer;
}
#endif
