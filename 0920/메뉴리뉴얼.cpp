#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void btk(const string& s, int idx, int need, string& cur,
                      unordered_map<string, int>& counter) {
    if(cur.size() == need)
    {
        ++counter[cur];
        return;
    }
    if(idx >= s.size())
    {
        return;
    }

    cur.push_back(s[idx]);
    btk(s, idx + 1, need, cur, counter);
    cur.pop_back();

    btk(s, idx + 1, need, cur, counter);
}

vector<string> solution(vector<string> orders, vector<int> course) {

    vector<string> answer;
    
    for(auto& o : orders)
    {
        sort(o.begin(), o.end());
    }

    for(int k : course)
    {
        unordered_map<string, int> counter;        

        for(const auto& order : orders)
        {
            if(order.size() < k)
            {
                continue;
            }
            string cur;
            btk(order, 0, k, cur, counter);
        }

        int best = 0;
        for(const auto& [comb, cnt] : counter)
        {
            if(cnt >= 2)
            {
                best = max(best, cnt);
            }
        }
        if(best < 2)
        {
            continue;
        }

        for(const auto& [comb, cnt] : counter)
        {
            if(cnt == best)
            {
                answer.push_back(comb);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}