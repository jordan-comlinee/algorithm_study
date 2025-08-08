#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<vector<int>> MAP;
int N, M;
queue<pair<int, int>> q;
vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

bool isIn(int r, int c)
{
    return 0 <= r && r < N && 0 <= c && c < M;
}

int fill(int n, int r, int c)
{
    int res = 1;
    MAP[r][c] = n;
    q.push({r, c});
    
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if (isIn(next_r, next_c) && MAP[next_r][next_c] == 1)
            {
                MAP[next_r][next_c] = n;
                res++;
                q.push({next_r, next_c});
            }
        }
    }

    return res;
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();
    MAP = land;
    int answer = 0;
    int idx = 2;
    unordered_map<int, int> m;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (MAP[i][j] == 1)
            {
                int res = fill(idx, i, j);
                m[idx] = res;
                idx++;
            }
        }
    }

    for (int j = 0; j < M; j++)
    {
        unordered_set<int> s;
        int temp = 0;
        for (int i = 0; i < N; i++)
        {
            s.insert(MAP[i][j]);
        }
        for (const auto& t : s)
        {
            temp += m[t];
        }
        answer = max(answer, temp);
    }
    return answer;
}

