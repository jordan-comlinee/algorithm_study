#include <string>
#include <vector>

using namespace std;

void dfs(int n, int st, int mid, int end, vector<vector<int>>& answer)
{
    if (n == 1)
    {
        answer.push_back({ st, end });
        return;
    }
    dfs(n - 1, st, end, mid, answer);
    answer.push_back({ st, end });
    dfs(n - 1, mid, st, end, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    dfs(n, 1, 2, 3, answer);

    return answer;
}


