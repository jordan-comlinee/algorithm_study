#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check_palindrome(string n)
{
    string r = n;
    reverse(r.begin(), r.end());

    if (r == n) return true;
    else return false;
}

int solution(string s)
{
    string word = "";

    for (int len = s.size(); len > 0; --len)
    {
        for (int attempt = 0; attempt + len <= s.size(); attempt++)
        {
            word = s.substr(attempt, len);
            if (check_palindrome(word)) return len;
        }
    }
}