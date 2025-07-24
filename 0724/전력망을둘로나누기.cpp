#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool ADJ[101][101];
bool visited[101];
int Ncount;

void DFS_Count(int Curr)
{
    visited[Curr] = true;
    Ncount++;

    for (int Next = 1; Next <= 100; ++Next)
    {
        if (ADJ[Curr][Next] && !visited[Next])
        {
            DFS_Count(Next);
        }
    }
    return;
}

void Count_Node(vector<vector<int>> wires)
{
    Ncount = 0;

    for (int i = 0; i < wires.size(); ++i)
    {
        ADJ[wires[i][0]][wires[i][1]] = true;
        ADJ[wires[i][1]][wires[i][0]] = true;
    }
    DFS_Count(1);

    fill(visited, visited + 101, false);
    fill(&ADJ[0][0], &ADJ[0][0] + 101 * 101, false);
}

int solution(int n, vector<vector<int>> wires)
{
    int min_diff = 1e9;
    int diff = 0;

    for (int i = 0; i < wires.size(); ++i)
    {
        vector<vector<int>> new_wires;

        for (int j = 0; j < wires.size(); ++j)
        {
            if (i == j) continue;
            new_wires.push_back(wires[j]);
        }
        Count_Node(new_wires);

        diff = abs((n - Ncount) - Ncount);

        if (diff <= min_diff)
        {
            min_diff = diff;
        }
    }
    return min_diff;
}