#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define dd 0
#define ll 1
#define rr 2
#define uu 3

int dx[4] = { 1, 0, 0,-1 };
int dy[4] = { 0,-1, 1, 0 };
char map[60][60];

char dirChar[4] = { 'd','l','r','u' };

int N;
int M;
int R;
int C;

bool check_valid(int x, int y)
{
    return (x >= 1) && (x <= N) && (y >= 1) && (y <= M);
}

string findroute(int startx, int starty, int dis, int movedis, string route)
{
    int remainDis = movedis - dis;
    int disToGoal = abs(R - startx) + abs(C - starty);

    if (remainDis < disToGoal)
    {
        return "impossible";
    }
    if ((remainDis - disToGoal) % 2 != 0)
    {
        return "impossible";
    }

    if (remainDis == 0)
    {
        if (map[startx][starty] == 'E')
        {
            return route;
        }
        return "impossible";
    }

    for (int i = 0; i < 4; ++i)
    {
        int Nextx = startx + dx[i];
        int Nexty = starty + dy[i];

        if (!check_valid(Nextx, Nexty))
        {
            continue;
        }

        string result = findroute(Nextx, Nexty, dis + 1, movedis, route + dirChar[i]);
        if (result != "impossible")
        {
            return result;
        }
    }

    return "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k) {

    N = n;
    M = m;
    R = r;
    C = c;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i == x) && (j == y))
            {
                map[i][j] = 'S';
            }
            else if ((i == r) && (j == c))
            {
                map[i][j] = 'E';
            }
            else
            {
                map[i][j] = '.';
            }
        }
    }

    int disToGoal = abs(r - x) + abs(c - y);

    if (k < disToGoal)
    {
        return "impossible";
    }
    if ((k - disToGoal) % 2 != 0)
    {
        return "impossible";
    }

    return findroute(x, y, 0, k, "");
}
