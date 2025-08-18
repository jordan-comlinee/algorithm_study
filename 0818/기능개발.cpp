#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> day;
    unordered_map<int, int> remainDays;
    const int progressesSize = progresses.size();
    
    for(int idx = 0; idx < progressesSize; ++idx)
    {
        remainDays.insert({idx, 100 - progresses[idx]});
    }
    
    for(int idx = 0; idx < progressesSize; ++idx)
    {
        const int remainDay = remainDays[idx];
        const int speedDay = speeds[idx];
        const int needDay = (remainDay + speedDay - 1) / speedDay;
        day.push_back(needDay);
    }
        
    
    if(!day.empty())
    {
        int curDay = day[0];
        int plusDay = 1;
        
        for(int idx = 1; idx < progressesSize; ++idx)
        {
            if(day[idx] <= curDay)
            {
                ++plusDay;
            }
            else
            {
                answer.push_back(plusDay);
                curDay = day[idx];
                plusDay  = 1;
            }
        }
        answer.push_back(plusDay);
    }
    
    return answer;
}