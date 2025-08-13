#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    map<int, string> subject;
    unordered_map<string, int> dur_time;
    stack<pair<int, int>> s;
    
    for(const auto& t : plans)
    {
        int h = stoi(t[1].substr(0, 2));
        int m = stoi(t[1].substr(3, 2));
        m += (h*60);
        subject[m] = t[0];
        dur_time[t[0]] = stoi(t[2]);
    }
    
    int end_time = 0;
    int prev = -1;
    for(const auto& t : subject)
    {
        if(t.first >= end_time)
        {
            if(prev!=-1)
                answer.push_back(subject[prev]);
            if(s.empty())
            {
                end_time = t.first + dur_time[t.second];
                prev = t.first;
            }
            else
            {
                while(!s.empty() && t.first != end_time)
                {
                    if(t.first - end_time >= s.top().second)
                    {
                        end_time+=s.top().second;
                        answer.push_back(subject[s.top().first]);
                        s.pop();
                    }
                    else
                    {
                        s.top().second -= (t.first - end_time);
                        if(s.top().second == 0)
                        {
                            answer.push_back(subject[s.top().first]);
                            s.pop();
                        }
                        end_time = t.first;
                    }
                }
                end_time = t.first + dur_time[t.second];
                prev = t.first;
            }
        }
        else
        {
            s.push({prev, end_time - t.first});
            end_time = t.first + dur_time[t.second];
            prev = t.first;
        }
    }
    answer.push_back(subject[prev]);
    while(!s.empty())
    {
        answer.push_back(subject[s.top().first]);
        s.pop();
    }
    return answer;
}
