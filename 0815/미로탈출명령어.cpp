#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dist(int pos_r, int pos_c, int r, int c)
{
    return abs(pos_r-r) + abs(pos_c-c);
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int pos_r = x;
    int pos_c = y;
    int cnt = 0;
    if(dist(x, y, r, c)>k)
        return "impossible";
    else if((k-dist(x, y, r, c))%2)
        return "impossible";
    while(cnt+dist(x, y, r, c)<k)
    {
        if(x<n)
        {
            x++;
            answer+="d";
        }
        else if(y>1)
        {
            y--;
            answer+="l";
        }
        else
        {
            y++;
            answer+="r";
        }
        cnt++;
    }
    while(x<r)
    {
        answer+="d";
        x++;
    }
    while(y>c)
    {
        answer+="l";
        y--;
    }
    while(y<c)
    {
        answer+="r";
        y++;
    }
    while(x>r)
    {
        answer+="u";
        x--;
    }
    return answer;
}
