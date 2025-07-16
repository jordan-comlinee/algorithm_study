#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    
    int u = 2100000000, l = 2100000000, r = -1, d = -1;
    for(int i = 0; i<wallpaper.size(); i++)
    {
        for(int j = 0; j<wallpaper[0].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i < u)
                    u = i;
                if(i > d)
                    d = i;
                if(j < l)
                    l = j;
                if(j > r)
                    r = j;
            }
        }
    }
    answer[0] = u;
    answer[1] = l;
    answer[2] = d+1;
    answer[3] = r+1;
    return answer;
}
