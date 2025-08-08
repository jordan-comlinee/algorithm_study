#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

bool isMatch(const string& user, const string& banned) {
    if (user.size() != banned.size()) return false;
    for (int i = 0; i < user.size(); ++i) {
        if (banned[i] == '*') continue;
        if (user[i] != banned[i]) return false;
    }
    return true;
}

int check(vector<string>& ban_list, vector<string>& banned_id)
{
    for (int i = 0; i < ban_list.size(); ++i)
    {
        if (!isMatch(ban_list[i], banned_id[i])) return 0;
    }
    static set<set<string>> unique_sets;
    set<string> current_set(ban_list.begin(), ban_list.end());
    if (current_set.size() != banned_id.size()) return 0;
    if (unique_sets.find(current_set) != unique_sets.end()) return 0;

    unique_sets.insert(current_set);
    return 1;
}

void dfs(vector<string>& user_id, vector<string> ban_list, vector<string>& banned_id, vector<bool> visited, int& answer)
{
    if (ban_list.size() == banned_id.size())
    {
        answer += check(ban_list, banned_id);
        return;
    }
    for (int i = 0; i < user_id.size(); ++i)
    {
        if (!visited[i])
        {
            ban_list.push_back(user_id[i]);
            visited[i] = true;
            dfs(user_id, ban_list, banned_id, visited, answer);
            ban_list.pop_back();
            visited[i] = false;
        }

    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int banned = banned_id.size();
    vector<string> ban_list;
    vector<bool> visited(user_id.size(), false);
    dfs(user_id, ban_list, banned_id, visited, answer);
    return answer;
}