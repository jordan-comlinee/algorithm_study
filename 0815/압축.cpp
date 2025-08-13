#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> algoMap;
    
    int idx = 0;
    for(; idx < 26; ++idx)
    {
        char c = 'A' + idx;
        string s(1, c);
        algoMap.insert({ s, idx + 1 });
    }
    
    string curStr = "";
    curStr += string(1, msg[0]);
    for (int i = 1; i < msg.size(); ++i)
    {
        string s(1, msg[i]);
        
        if (algoMap.find(curStr + s) != algoMap.end())
        {
            curStr += s;
        }
        else
        {
            answer.push_back(algoMap.find(curStr)->second);

            algoMap.insert({ curStr + s, ++idx });

            curStr = s;
        }
    }
    
    answer.push_back(algoMap.find(curStr)->second);
    
    return answer;
}