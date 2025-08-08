#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long calculate(vector<int>& prior, string& expression)
{
    long long result = 0;
    char oper[3] = { '*', '+', '-' };
    unordered_map<char, int> prec;
    for (int i = 0; i < 3; ++i) prec[oper[prior[i]]] = i;
    stack<char> ops;
    string num;
    stack<long long> val;
    for (auto exp : expression)
    {
        if (isdigit(exp))
        {
            num += exp;
        }
        else
        {
            if (!num.empty())
            {
                val.push(stoll(num));
                num.clear();
            }
            while (!ops.empty() && prec[ops.top()] <= prec[exp])
            {
                long long b = val.top(); val.pop();
                long long a = val.top(); val.pop();
                char op = ops.top(); ops.pop();

                long long v;
                if (op == '+') v = a + b;
                else if (op == '-') v = a - b;
                else v = a * b; // '*'

                val.push(v);
            }
            ops.push(exp);
        }
    }

    if (!num.empty()) {
        val.push(stoll(num));
        num.clear();
    }

    while (!ops.empty()) {
        long long b = val.top(); val.pop();
        long long a = val.top(); val.pop();
        char op = ops.top(); ops.pop();

        long long v;
        if (op == '+') v = a + b;
        else if (op == '-') v = a - b;
        else v = a * b;

        val.push(v);
    }

    return abs(val.top());
}

long long solution(string expression) {
    long long answer = 0;
    vector<vector<int>> prior = { {0, 1, 2}, {1, 0, 2}, {0, 2, 1}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0} };
    for (auto pr : prior)
    {
        answer = max(answer, calculate(pr, expression));
    }

    return answer;
}