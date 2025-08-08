#include <iostream>
#include <string>
using namespace std;

int check(string s, int st, int end)
{
    while (0 <= st && st < s.size() && 0 <= end && end < s.size() && s[st] == s[end])
    {
        st--;
        end++;
    }
    return end - st - 1;
}

int solution(string s)
{
    int answer = 1;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            answer = max(check(s, i, i + 1), answer);
        }
        answer = max(check(s, i + 1, i - 1), answer);
    }

    return answer;
}