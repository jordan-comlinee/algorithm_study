#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define Rect -2
#define Route -1

using namespace std;

int map[60][60] = { 0 };
bool visited[60][60] = { 0 };

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void draw_rect(vector<int> rect)
{
    for (int i = rect[0]; i <= rect[2]; ++i)
    {
        for (int j = rect[1]; j <= rect[3]; ++j)
        {
            map[i][j] = Rect;
        }
    }
}

void draw_road()
{
    for (int i = 0; i < 60; ++i)
    {
        for (int j = 0; j < 60; ++j)
        {
            if (map[i][j] == Rect)
            {
                if (map[i][j - 1] != Rect || map[i][j + 1] != Rect ||
                    map[i - 1][j] != Rect || map[i + 1][j] != Rect ||
                    map[i - 1][j - 1] != Rect || map[i + 1][j + 1] != Rect ||
                    map[i - 1][j + 1] != Rect || map[i + 1][j - 1] != Rect)
                {
                    map[i][j] = Route;
                }
            }
        }
    }
}

void find_dis(int startX, int startY)
{
    queue<pair<int, int>> Q;
    map[startX][startY] = 0;
    visited[startX][startY] = true;

    Q.push(make_pair(startX, startY));

    while (!Q.empty())
    {
        pair<int, int> Curr = Q.front();
        Q.pop();

        int CurrX = Curr.first;
        int CurrY = Curr.second;

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurrX + dx[i];
            int NextY = CurrY + dy[i];

            if (!visited[NextX][NextY] && map[NextX][NextY] == Route)
            {
                visited[NextX][NextY] = true;
                map[NextX][NextY] = map[CurrX][CurrY] + 1;

                cout << CurrX << " " << CurrY << "TO" << NextX << " " << NextY << " " << map[NextX][NextY] << endl;
                Q.push(make_pair(NextX, NextY));
            }
        }
    }
    return;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (int r = 0; r < rectangle.size(); ++r)
    {
        draw_rect(rectangle[r]);
    }
    draw_road();
    find_dis(characterX, characterY);

    return map[itemX][itemY];
}