#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    unordered_map<string, vector<pair<int, int>>> head_map;
    set<string> s;
    int index = 0;
    for(const auto& t : files)
    {
        string head = "";
        string string_num = "";
        int num = 0;
        int i = 0;
        for(; i<t.size(); i++)
        {
            if(isdigit(t[i]))
                break;
            else if(isupper(t[i]))
                head += tolower(t[i]);
            else
                head += t[i];
        }
        for(; i<t.size(); i++)
        {
            if(!isdigit(t[i]))
                break;
            string_num+=t[i];
            
        }
        s.insert(head);
        num = stoi(string_num);
        head_map[head].push_back({index, num});
        index++;
    }
    for(const auto& t : s)
    {
        stable_sort(head_map[t].begin(), head_map[t].end(), comp);
        for(int i = 0; i < head_map[t].size(); i++)
        {
            answer.push_back(files[head_map[t][i].first]);
        }
    }
    return answer;
}
