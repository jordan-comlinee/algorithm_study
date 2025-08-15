#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {

    map<string, int> dict;

    for (int i = 65; i <= 90; ++i)
    {
        string temp = "";
        temp += (char)i;
        dict.insert({ temp, i - 64 });
    }

    int next_idx = 27;
    vector<int> answer;

    for (int i = 0; i < msg.size(); )
    {
        string w = "";
        string next = "";
        int j = i;

        while (j < msg.size())
        {
            next = w + msg[j];
            if (dict.find(next) != dict.end())
            {
                w = next;
                ++j;
            }
            else
            {
                break;
            }
        }

        answer.push_back(dict[w]);

        if (j < msg.size())
        {
            string next = w + msg[j];
            dict.insert({ next, next_idx });
            next_idx++;
        }

        i += w.size();
    }

    return answer;
}
