#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string temp = "";
    unordered_map<int, int> m;
    int max = 0;
    for(const auto& t : s)
    {
        if(t=='{')
            continue;
        else if(t=='}' || t==',')
        {
            if(temp!="")
            {
                int num = stoi(temp);
                m[num]++;
                if(m[num]>max)
                    max = m[num];
            }
            
            temp="";
        }
        else
            temp+=t;
    }
    answer.resize(max, 0);
    for(const auto& t : m)
    {
        answer[t.second-1] = t.first;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}