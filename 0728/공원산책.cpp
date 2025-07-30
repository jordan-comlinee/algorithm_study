#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<int>> map(park.size()+2, vector<int>(park[0].size()+2, 0));
    int y = 0, x = 0;
    vector<int> dy = {0, 0, 1, -1};
    vector<int> dx = {1, -1, 0, 0};
    
    for(int i = 0; i<park.size(); i++)
    {
        for(int j = 0; j<park[0].size(); j++)
        {
            if(park[i][j] == 'O')
            {
                map[i+1][j+1] = 1;
            }
            else if(park[i][j] == 'X')
                continue;
            else
            {
                y = i+1;
                x = j+1;
                map[i+1][j+1] = 1;
            }
        }
    }
    for(const auto& t : routes)
    {
        int d = t[0];
        if(t[0] == 'E')
            d = 0;
        else if(t[0]=='W')
            d = 1;
        else if(t[0]=='S')
            d = 2;
        else
            d = 3;
        int t_x = 0, t_y = 0;
        bool para = false;
        for(int i = 0; i<(int)(t[2]-'0'); i++)
        {
            if(map[y+t_y+dy[d]][x+t_x+dx[d]])
            {
                t_y+=dy[d];
                t_x+=dx[d];
            }
            else
            {
                para = true;
                break;
            }
        }
        if(para==false)
        {
            y+=t_y;
            x+=t_x;
        }
    }
    answer.push_back(y-1);
    answer.push_back(x-1);
    
    return answer;
}