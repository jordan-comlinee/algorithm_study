#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

const int dx[4] = { 1, 0, 0, -1 };
const int dy[4] = { 0, -1, 1, 0 };
const char dir[4] = { 'd', 'l', 'r', 'u' };

void dfs(int n, int m, int x, int y, const int r, const int c, int k, string path, string& answer)
{
    int dist = abs(x - r) + abs(y - c);
    if (dist > k) return;
    if ((k - dist) % 2 != 0) return;
    if (!answer.empty()) return;
    if (k == 0)
    {
        if (x == r && y == c)
        {
            //cout << "possible" << endl;
            answer = path;
        }
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            dfs(n, m, nx, ny, r, c, k - 1, path + dir[i], answer);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int dist = abs(x - r) + abs(y - c);
    if (dist > k) return "impossible";
    dfs(n, m, x - 1, y - 1, r - 1, c - 1, k, "", answer);
    return answer == "" ? "impossible" : answer;
}