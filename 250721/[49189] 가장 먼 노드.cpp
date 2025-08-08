#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<bool>> ADJ;
vector<bool> Visited;
vector<int> Distance;

void BFS_Find(int start)
{
    Visited[start] = true;
    Distance[start] = 0;

    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int Curr = Q.front();
        Q.pop();

        for (int Next = 1; Next < ADJ.size(); ++Next)
        {
            if (ADJ[Curr][Next] && !Visited[Next])
            {
                Q.push(Next);
                Visited[Next] = true;
                Distance[Next] = Distance[Curr] + 1;
            }
        }
    }
    return;
}

int solution(int n, vector<vector<int>> edge) {

    Visited.resize(n + 1);
    Distance.resize(n + 1);
    ADJ.resize(n + 1);

    for (int i = 0; i <= n; ++i)
    {
        ADJ[i].resize(n + 1);
    }

    for (int i = 0; i < edge.size(); ++i)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        ADJ[u][v] = true;
        ADJ[v][u] = true;
    }

    BFS_Find(1);

    int max_distance = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (Distance[i] > max_distance)
        {
            max_distance = Distance[i];
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (Distance[i] == max_distance)
        {
            answer++;
        }
    }

    return answer;
}
