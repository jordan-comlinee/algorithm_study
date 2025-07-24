#if 0
// seongho
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
#endif
#if 0
// jihoon
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct fileInfo
{
    string init;
    string head;
    int number;
    int idx;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    int filesSize = files.size();
    vector<fileInfo> fInfo;
    
    for (int idx = 0; idx < filesSize; ++idx)
    {
        const string& file = files[idx];
        // head/number/tail
        int i = 0;
        int len = file.size();
        string head = "";
        string number = "";

        while (i < len && !(file[i] >= '0' && file[i] <= '9'))
        {
            head += file[i++];
        }

        while (i < len && (file[i] >= '0' && file[i] <= '9') && number.size() < 5)
        {
            number += file[i++];
        }

        string tolowerHead = head;
        for (int j = 0; j < tolowerHead.size(); ++j)
        {
            if (tolowerHead[j] >= 'A' && tolowerHead[j] <= 'Z')
            {
                tolowerHead[j] = tolowerHead[j] - 'A' + 'a';
            }
        }
        fInfo.push_back({file, tolowerHead, stoi(number), idx});
    }
            
    sort(fInfo.begin(), fInfo.end(), [](const fileInfo& a, const fileInfo& b){
        if(a.head != b.head)
        {
            return a.head < b.head;
        }
        if(a.number != b.number)
        {
            return a.number < b.number;
        }
        return a.idx < b.idx;
    });
    
    for (const auto& info : fInfo)
    {
        answer.push_back(info.init);
    }
    
    return answer;
}
#endif
