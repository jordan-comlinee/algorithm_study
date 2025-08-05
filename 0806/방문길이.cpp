#include <string>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };


bool inRange(pair<int, int> p)
{
    return (abs(p.first) <= 5 && abs(p.second) <= 5);
}

int solution(string dirs) {
    int answer = 0;
    unordered_map<char, int> d{ {'U', 0}, {'D', 1}, {'R', 2}, {'L', 3} };
    bool visited[11][11][11][11] = {};
    pair<int, int> cur = { 0, 0 };
    for (int i = 0; i < dirs.size(); ++i)
    {
        int nd = d[dirs[i]];
        pair<int, int> move = { cur.first + dx[nd], cur.second + dy[nd] };
        if (inRange(move))
        {
            if (!visited[cur.first + 5][cur.second + 5][move.first + 5][move.second + 5] || !visited[move.first + 5][move.second + 5][cur.first + 5][cur.second + 5])
            {
                answer++;
                visited[cur.first + 5][cur.second + 5][move.first + 5][move.second + 5] = true;
                visited[move.first + 5][move.second + 5][cur.first + 5][cur.second + 5] = true;
            }
            cur = move;
        }


    }
    return answer;
}