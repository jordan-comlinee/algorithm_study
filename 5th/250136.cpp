#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

pair<int, set<int>> bfs(int x, int y, const vector<vector<int>>& land, vector<vector<bool>>& visited) {
    int h = land.size();
    int w = land[0].size();
    int amount = 1;
    set<int> oil_range;
    queue<pair<int, int>> q;
    q.push({x, y});
    oil_range.insert(y);
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (0 <= nx && nx < h && 0 <= ny && ny < w &&
                land[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                amount++;
                oil_range.insert(ny);
                q.push({nx, ny});
            }
        }
    }

    return {amount, oil_range};
}

int solution(vector<vector<int>> land) {
    int h = land.size();
    int w = land[0].size();
    vector<int> answer(w, 0);
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            if (land[x][y] == 1 && !visited[x][y]) {
                pair<int, set<int>> oils = bfs(x, y, land, visited);
                for (int col : oils.second) {
                    answer[col] += oils.first;
                }
            }
        }
    }

    return *max_element(answer.begin(), answer.end());
}
