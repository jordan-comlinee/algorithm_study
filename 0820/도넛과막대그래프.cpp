#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> Graph[1000001];
vector<int> Answer(4);
int InDegree[1000001];
int OutDegree[1000001];

void BFS_Search(int Start)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(Start, 0));

    bool IsCycle = false;
    int Count = 0;

    while (!Q.empty())
    {
        int Curr = Q.front().first;
        int Dist = Q.front().second;
        Q.pop();

        if (IsCycle)
        {
            if (Count == Dist)
                Answer[1]++;
            else
                Answer[3]++;
            return;
        }

        for (int i = 0; i < Graph[Curr].size(); i++)
        {
            int Next = Graph[Curr][i];

            if (Start == Next)
                IsCycle = true;

            Q.push(make_pair(Next, Dist + 1));
            Count++;
        }
    }

    Answer[2]++;
}

vector<int> solution(vector<vector<int>> Edges)
{
    int MaxNode = 0;

    for (int i = 0; i < Edges.size(); i++)
    {
        int From = Edges[i][0];
        int To = Edges[i][1];

        InDegree[To]++;
        OutDegree[From]++;
        Graph[From].push_back(To);
    }

    for (int i = 1; i <= 1000000; i++)
    {
        if (InDegree[i] == 0 && OutDegree[i] >= 2)
        {
            Answer[0] = i;
            break;
        }
    }

    for (int i = 0; i < Graph[Answer[0]].size(); i++)
    {
        int Node = Graph[Answer[0]][i];
        BFS_Search(Node);
    }

    return Answer;
}
