#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    unordered_map<string, string> tree;
    unordered_map<string, int> profit;
    for (int i = 0; i < enroll.size(); ++i)
    {
        profit[enroll[i]] = 0;
        tree[enroll[i]] = referral[i];
    }
    queue<pair<string, int>> q;
    for (int i = 0; i < seller.size(); ++i)
    {
        q.push({ seller[i], amount[i] * 100 });
    }
    while (!q.empty())
    {
        auto [sell, prof] = q.front();
        q.pop();
        int give = prof / 10;
        int keep = prof - give;
        if (tree[sell] != "-" && give > 0)
        {
            q.push({ tree[sell], give });
        }
        profit[sell] += keep;
    }
    for (int i = 0; i < enroll.size(); ++i) {
        answer[i] = profit[enroll[i]];
    }
    return answer;
}