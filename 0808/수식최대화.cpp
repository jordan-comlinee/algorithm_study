#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string LastString(int idx, string str)
{
    string answer = "";

    int i = idx;
    while (1)
    {
        answer += str[i];
        i--;
        if (str[i] == '+' || str[i] == '-' || str[i] == '*') break;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

string SubString(int idx, string str, char op)
{
    string answer = "";

    int i = idx;
    while (1)
    {
        answer += str[i];
        if (i == 0) break;
        i--;
        if (str[i] == '+' || str[i] == '-' || str[i] == '*') break;
    }

    if (str[i] == op)
    {
        answer = "";
        answer += str[idx];
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

string SubCal(int idx, string str)
{
    string num1 = "";
    string num2 = "";

    int i = idx - 1;
    while (1)
    {
        num1 += str[i];
        if (i == 0) break;
        i--;
        if (str[i] == '+' || str[i] == '-' || str[i] == '*') break;
    }

    i = idx + 1;
    while (1)
    {
        num2 += str[i];
        if (i == str.size() - 1) break;
        i++;
        if (str[i] == '+' || str[i] == '-' || str[i] == '*') break;
    }

    reverse(num1.begin(), num1.end());

    if (str[i] == '+') return to_string(stoll(num1) + stoll(num2));
    if (str[i] == '-') return to_string(stoll(num1) + stoll(num2));
    if (str[i] == '*') return to_string(stoll(num1) + stoll(num2));
}

long long Calulate(string expression, vector<char> op)
{
    string exp = expression;
    string temp_exp = "";

    for (int i = 0; i < op.size(); ++i)
    {
        for (int j = 0; j < exp.size(); ++j)
        {
            if (exp[j] == op[i])
            {
                temp_exp += SubCal(j, exp);
            }
            else if (j == exp.size() - 1)
            {
                temp_exp += LastString(j, exp);
            }
            else if (exp[j] == '*' || exp[j] == '-' || exp[j] == '+')
            {
                temp_exp += SubString(j, exp, op[i]);
            }
        }
        exp = temp_exp;
    }
}

long long solution(string expression) {

    vector<char> op = { '*','-','+' };

    cout << SubCal(2, "50+60-3") << endl;
    cout << SubString(5, "50+60-3", '+') << endl;
    do {

        for (int i = 0; i < 3; ++i)
        {
            cout << op[i];
        }
        cout << endl;

    } while (next_permutation(op.begin(), op.end()));


    for (int i = 0; i < 3; ++i)
    {
        cout << op[i];
    }
    cout << endl;

    long long answer = 0;
    return answer;
}