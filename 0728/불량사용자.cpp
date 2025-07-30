#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

bool isMatch(const string& user, const string& ban) {
    if (user.size() != ban.size()) return false;
    for (int i = 0; i < user.size(); ++i) {
        if (ban[i] == '*') continue;
        if (user[i] != ban[i]) return false;
    }
    return true;
}

void dfs(int idx, const vector<string>& banned_id, const vector<vector<string>>& m,
         unordered_set<string>& used, set<set<string>>& result) {
    if (idx == banned_id.size()) {
        result.insert(set<string>(used.begin(), used.end()));  // ← 핵심 수정
        return;
    }

    for (const auto& user : m[idx]) {
        if (used.count(user)) continue;
        used.insert(user);
        dfs(idx + 1, banned_id, m, used, result);
        used.erase(user);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    // banned_id 순서대로 가능한 user_id 리스트 저장
    vector<vector<string>> m(banned_id.size());
    for (int i = 0; i < banned_id.size(); ++i) {
        for (const auto& user : user_id) {
            if (isMatch(user, banned_id[i])) {
                m[i].push_back(user);
            }
        }
    }

    // DFS로 가능한 조합을 모두 탐색하며, 중복 제거
    set<set<string>> result;
    unordered_set<string> used;
    dfs(0, banned_id, m, used, result);

    return result.size();
}
