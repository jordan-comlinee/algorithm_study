#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string revolve(string s)
{
    string answer = "";
    answer = s[s.size() - 1];

    for (int i = 0; i < s.size() - 1; ++i)
    {
        answer += s[i];
    }
    return answer;
}

bool validstring(string s)
{
    stack<char> S;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            S.push(c);
        }
        else
        {
            if (S.empty()) return false;

            char top = S.top();
            S.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return S.empty();
}

int solution(string s) {

    int answer = 0;
    string w = s;

    cout << validstring("()(){[") << endl;

    for (int i = 0; i < w.size(); ++i)
    {
        w = revolve(w);
        if (validstring(w)) answer++;
    }
    return answer;
}