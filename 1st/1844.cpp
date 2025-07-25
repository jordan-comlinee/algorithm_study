#include<vector>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(int n, int m, int y, int x, vector<vector<int>> &maps, vector<vector<int>> &dist)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    dist[y][x] = 1;
    
    while(!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i)
        {            
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && maps[ny][nx] && !dist[ny][nx])
            {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }
    return dist[n - 1][m - 1] == 0 ? -1 : dist[n - 1][m - 1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0; 
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    answer = bfs(n, m, 0, 0, maps, dist);
    
    return answer;
}