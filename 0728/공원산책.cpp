#include <string>
#include <vector>

#define N 0
#define W 1
#define S 2
#define E 3

using namespace std;

vector<string> map;
pair<int, int> Curr;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,-1,0,1 };

bool check_valid(int i, int j)
{
    return i >= 0 && i < map.size() && j >= 0 && j < map[0].size();
}

void MoveToward(char dir, int dis)
{
    int Curri = Curr.first;
    int Currj = Curr.second;
    int direction;

    if (dir == 'N') direction = N;
    if (dir == 'W') direction = W;
    if (dir == 'E') direction = E;
    if (dir == 'S') direction = S;

    for (int i = 0; i < dis; ++i)
    {
        Curri += di[direction];
        Currj += dj[direction];

        if (!check_valid(Curri, Currj))
        {
            return;
        }
        else if (map[Curri][Currj] == 'X')
        {
            return;
        }
    }
    Curr.first += di[direction] * dis;
    Curr.second += dj[direction] * dis;
    return;
}

vector<int> solution(vector<string> park, vector<string> routes) {

    map = park;
    vector<int> answer;

    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[0].size(); ++j)
        {
            if (map[i][j] == 'S')
            {
                Curr.first = i;
                Curr.second = j;
                break;
            }
        }
    }
    for (int i = 0; i < routes.size(); ++i)
    {
        MoveToward(routes[i][0], (int)(routes[i][2] - '0'));
    }

    answer.push_back(Curr.first);
    answer.push_back(Curr.second);
    return answer;
}