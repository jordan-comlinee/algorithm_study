#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> map;
    char last = ' ';
    for (int i = 0; i < words.size(); ++i)
    {
        if ((last == ' ') || (last == words[i][0] && map.find(words[i]) == map.end()))
        {
            int size = words[i].size();
            last = words[i][size - 1];
            map[words[i]] = true;
        }
        else
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }

    }

    if (answer.size() == 0)
    {
        answer = { 0, 0 };
    }
    return answer;
}