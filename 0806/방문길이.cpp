#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define U 0
#define D 1
#define R 2
#define L 3

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<pair< pair<int, int>, pair<int, int> >> visited;

int solution(string dirs) {

    int answer = 0;
    int NextX = 0;
    int NextY = 0;

    pair<int, int> Curr = make_pair(0, 0);

    for (int num = 0; num < dirs.size(); ++num)
    {
        int CurrX = Curr.first;
        int CurrY = Curr.second;

        if (dirs[num] == 'U')
        {
            NextX = CurrX + dx[U];
            NextY = CurrY + dy[U];
        }
        if (dirs[num] == 'D')
        {
            NextX = CurrX + dx[D];
            NextY = CurrY + dy[D];
        }
        if (dirs[num] == 'R')
        {
            NextX = CurrX + dx[R];
            NextY = CurrY + dy[R];
        }
        if (dirs[num] == 'L')
        {
            NextX = CurrX + dx[L];
            NextY = CurrY + dy[L];
        }
        if (NextX >= -5 && NextX <= 5 && NextY >= -5 && NextY <= 5)
        {
            pair<int, int> Next = make_pair(NextX, NextY);

            bool c1 = find(visited.begin(), visited.end(), make_pair(Curr, Next)) == visited.end();
            bool c2 = find(visited.begin(), visited.end(), make_pair(Next, Curr)) == visited.end();

            if (c1 && c2)
            {
                answer++;
                visited.push_back(make_pair(Curr, Next));
            }
            Curr = Next;
        }
    }
    return answer;
}