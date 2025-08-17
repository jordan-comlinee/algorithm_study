#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

void makeLib(unordered_map<string, int>& lib)
{
    for (int i = 0; i < 26; ++i)
    {
        char ch = 'A' + i;
        string key(1, ch);
        lib[key] = i + 1;
    }
}

string find(const unordered_map<string, int>& lib, const string& msg, const int& idx, int& c)
{
    for (int i = c; i > 0; --i)
    {
        string k = msg.substr(idx, i);
        if (lib.find(k) != lib.end()) return k;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> lib;
    int idx = 0;
    int c = 1;
    int val = 27;
    makeLib(lib);

    while (idx < msg.size())
    {
        // 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
        string w = find(lib, msg, idx, c);
        // w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
        answer.push_back(lib[w]);
        idx += w.size();
        // 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
        if (idx < msg.size())
        {
            if (lib.find(w + msg[idx]) == lib.end())
            {
                lib[w + msg[idx]] = val++;
                int newKeySize = (w + msg[idx]).size();
                c = max(c, newKeySize);
            }

        }
    }
    return answer;
}