#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer;
    unordered_map<int, int> m;
    for(const auto& t : win_nums)
    {
        m[t]++;        
    }
    int cnt = 0;
    int z_cnt = 0;
    for(const auto& t : lottos)
    {
        if(t==0)
            z_cnt++;
        else if(m[t])
            cnt++;
    }
    if(cnt+z_cnt>1)
        answer.push_back(7-(cnt+z_cnt));
    else
        answer.push_back(6);
    if(cnt>1)
        answer.push_back(7-(cnt));
    else
        answer.push_back(6);
    
    
    return answer;
}
