#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string to_binary(int n, int len)
{
    string answer = "";
    while (n > 0)
    {
        answer = to_string(n % 2) + answer;
        n /= 2;
    }

    while (answer.length() < len)
    {
        answer = '0' + answer;
    }
    return answer;
}

string Change(string b)
{
    string answer = "";
    for (int i = 0; i < b.size(); ++i)
    {
        if (b[i] == '0')
        {
            answer += ' ';
        }
        else if (b[i] == '1')
        {
            answer += '#';
        }
    }
    return answer;
}

string Combine(string n1, string n2)
{
    string answer = "";
    for (int i = 0; i < n1.size(); ++i)
    {
        if (n1[i] == ' ' && n2[i] == ' ')
        {
            answer += ' ';
        }
        else
        {
            answer += '#';
        }
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for (int i = 0; i < n; ++i)
    {
        answer.push_back(Combine(Change(to_binary(arr1[i], n)), Change(to_binary(arr2[i], n))));
    }
    return answer;
}