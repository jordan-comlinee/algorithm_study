#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.size();
    for (int i = 0; i < size; ++i)
    {
        stack<char> stack;
        bool valid = true;
        for (int j = i; j < i + size; ++j)
        {
            int idx = j % size;
            if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[')
            {
                stack.push(s[idx]);
            }
            else
            {
                if (stack.empty()) valid = false;
                else if (s[idx] == ')' && stack.top() != '(') valid = false;
                else if (s[idx] == '}' && stack.top() != '{') valid = false;
                else if (s[idx] == ']' && stack.top() != '[') valid = false;
                else stack.pop();
            }
            if (!valid) break;
        }
        answer += (valid && stack.empty()) ? 1 : 0;
    }
    return answer;
}