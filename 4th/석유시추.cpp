#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs(int y, int x, int oilSetId, const int n, const int m, const vector<vector<int>>& land, vector<vector<int>>& visited, unordered_map<int, int>& oilMap, unordered_map<int, set<int>>& oilX
)
{
    int oilNum = 0;
    queue<pair<int, int>> q;
    
    q.push({y, x});
    visited[y][x] = oilSetId;
    oilX[oilSetId].insert(x);
    ++oilNum;

    while(!q.empty())
    {
        auto [cy, cx] = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(land[ny][nx] == 1 && visited[ny][nx] == 0)
                {
                    visited[ny][nx] = oilSetId;
                    oilX[oilSetId].insert(nx);
                    ++oilNum;
                    q.push({ny, nx});
                }
            }
        }
    }

    oilMap[oilSetId] = oilNum;
    return oilNum;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    const int n = land.size();
    const int m = land[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    unordered_map<int, int> oilMap;
    unordered_map<int, set<int>> oilX;

    int oilSetId = 1;
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
            if(land[y][x] == 1 && visited[y][x] == 0)
            {
                bfs(y, x, oilSetId, n, m, land, visited, oilMap, oilX);
                ++oilSetId;
            }
        }
    }

    vector<int> colOil(m, 0);
    for(auto& [id, cols] : oilX)
    {
        for(int x : cols)
        {
            colOil[x] += oilMap[id];
        }
    }
    
    answer = *max_element(colOil.begin(), colOil.end());
    
    return answer;
}
