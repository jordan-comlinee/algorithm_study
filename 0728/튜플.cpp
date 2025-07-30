#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool compare(const vector<int> a, const vector<int> b)
{
    return a.size() < b.size();
}

int toInt(const string s, int i)
{
    int num = 0;
    while (i < s.size() && isdigit(s[i]))
    {
        num = num * 10 + (s[i] - '0');
        ++i;
    }
    return num;
}

bool contains(const vector<int> v, int num)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == num) return true;
    }
    return false;
}

vector<int> solution(string s)
{
    vector<vector<int>> sets;
    vector<int> answer;

    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '{')
        {
            ++i;
            vector<int> temp;

            while (s[i] != '}')
            {
                if (isdigit(s[i]))
                {
                    int num = toInt(s, i);
                    temp.push_back(num);
                }
                else
                {
                    ++i;
                }
            }
            sets.push_back(temp);
        }
        ++i;
    }

    sort(sets.begin(), sets.end(), compare);

    for (int j = 0; j < sets.size(); ++j)
    {
        for (int k = 0; k < sets[j].size(); ++k)
        {
            if (!contains(answer, sets[j][k]))
            {
                answer.push_back(sets[j][k]);
                break;
            }
        }
    }
    return answer;
}
