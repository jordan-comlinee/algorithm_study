#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int, int> X;
unordered_map<int, int> Y;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
bool isOn(vector<int> rec, int x, int y)
{
    if(rec[0] == x || rec[2] == x)
    {
        if(rec[1] <= y && y <= rec[3])
            return true;
    }
    if(rec[1] == y || rec[3] == y)
    {
        if(rec[0] <= x && x <= rec[2])
            return true;
    }
    return false;
}

bool isIn(vector<int> rec, int x, int y)
{
    if(rec[0] < x && x < rec[2] && rec[1] < y && y < rec[3])
        return true;
    return false;
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> Rectangle(1);
    int index = 1;
    for(auto t : rectangle)
    {
        Rectangle.push_back(t);
        X[t[0]] = index;
        X[t[2]] = index;
        Y[t[1]] = index;
        Y[t[3]] = index;
        index++;
    }
    int dist = 0, dist2 = 0;
    int temp;
    int dir;
    int x = characterX;
    int y = characterY;
    if(X[x])
    {
        vector<int> t = Rectangle[X[x]];
        if(isOn(t, characterX, characterY))
        {
            temp = X[characterX];
            dir = 0;
        }
        
    }
    else
    {
        temp = Y[characterY];
        dir = 1;
    }
    

    int f_dir = dir;

    while(true)
    {
        if(x==itemX && y==itemY)
            break;
        bool n_temp = false;
        int new_temp = 0;
        if(X[x])
        {
            if(temp != X[x])
            {
                n_temp = true;
                new_temp = X[x];
            }
        }
        if(Y[y])
        {
            if(temp != Y[y])
            {
                n_temp = true;
                new_temp = Y[y];
            }
        }
        if(n_temp==false)
        {
            if(isOn(Rectangle[temp], x+dx[dir], y+dy[dir]))
            {
                x+=dx[dir];
                y+=dy[dir];
            }
            else
            {
                dir = (dir+1)%4;
                if(isOn(Rectangle[temp], x+dx[dir], y+dy[dir]))
                {
                    x+=dx[dir];
                    y+=dy[dir];
                }
                else
                {
                    dir = (dir+2)%4;
                    x+=dx[dir];
                    y+=dy[dir];
                }
            }
        }
        else
        {
            dir = (dir+1)%4;
            if(isIn(Rectangle[temp], x+dx[dir], y+dy[dir]))
            {
                dir = (dir+2)%4;
            }
            x+=dx[dir];
            y+=dy[dir];
            temp = new_temp;
        }
        dist++;
    }
    dir = (f_dir+2)%4;
    x= characterX, y = characterY;
    while(true)
    {
        if(x==itemX && y==itemY)
            break;
        bool n_temp = false;
        int new_temp = 0;
        if(X[x])
        {
            if(temp != X[x])
            {
                n_temp = true;
                new_temp = X[x];
            }
        }
        if(Y[y])
        {
            if(temp != Y[y])
            {
                n_temp = true;
                new_temp = Y[y];
            }
        }
        if(n_temp==false)
        {
            if(isOn(Rectangle[temp], x+dx[dir], y+dy[dir]))
            {
                x+=dx[dir];
                y+=dy[dir];
            }
            else
            {
                dir = (dir+1)%4;
                if(isOn(Rectangle[temp], x+dx[dir], y+dy[dir]))
                {
                    x+=dx[dir];
                    y+=dy[dir];
                }
                else
                {
                    dir = (dir+2)%4;
                    x+=dx[dir];
                    y+=dy[dir];
                }
            }
        }
        else
        {
            dir = (dir+1)%4;
            if(isIn(Rectangle[temp], x+dx[dir], y+dy[dir]))
            {
                dir = (dir+2)%4;
            }
            x+=dx[dir];
            y+=dy[dir];
            temp = new_temp;
        }
        dist2++;
    }
    answer = min(dist, dist2);
    return answer;
}
