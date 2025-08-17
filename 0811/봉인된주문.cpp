// 26진수 같은 개념
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long spell(string& ban)
{
    long long result = 0;
    long long a = 1;
    for (int i = ban.size() - 1; i >= 0; --i)
    {
        result += (ban[i] - 'a' + 1) * a;
        a *= 26;
    }
    return result;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<long long> llBans;
    // sort(bans.begin(), bans.end(), [](const string& a, const string&b) {
    //     return spell(const_cast<string&> (a)) < spell(const_cast<string&> (b));
    // });
    for (auto ban : bans)
    {
        llBans.push_back(spell(ban));
        //cout << ban << " " << spell(ban) << endl;
        //if(spell(ban) <= n) n++;
    }
    sort(llBans.begin(), llBans.end());
    for (auto ban : llBans)
    {
        if (ban <= n) ++n;
        else break;
    }
    while (n > 0)
    {
        answer += 'a' + (--n % 26);
        n /= 26;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}