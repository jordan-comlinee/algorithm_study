#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    int idx = 0;
    string alphabet = "";
    sort(skip.begin(), skip.end());
    for (int i = 0; i < 26; ++i)
    {
        if (skip[idx] == 'a' + i)
        {
            idx += 1;
        }
        else
        {
            alphabet += 'a' + i;
        }
    }
    for (auto t : s)
    {
        int pos = alphabet.find(t);
        answer += alphabet[(pos + index) % alphabet.size()];
    }
    return answer;
}