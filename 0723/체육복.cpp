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