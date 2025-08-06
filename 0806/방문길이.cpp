#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
bool isIn(int r, int c)
{
    if(0<=r&&r<=10&&0<=c&&c<=10)
        return true;
    return false;
}
int solution(string dirs) {
    int answer = 0;
    unordered_map<char, pair<int, int>> m;
    m['L'] = {0, -1};
    m['R'] = {0, 1};
    m['U'] = {-1, 0};
    m['D'] = {1, 0};
    vector<vector<bool>> v_r(11, vector<bool>(10, false));
    vector<vector<bool>> v_c(10, vector<bool>(11, false));
    int r = 5, c =5;
    for(const auto& t : dirs)
    {
        auto temp = m[t];
        if(isIn(r+temp.first, c+temp.second))
        {
            if(t=='L'||t=='R')
            {
                if(v_r[r][min(c, c+temp.second)]==false)
                {
                    v_r[r][min(c, c+temp.second)]=true;
                    answer++;
                }
            }
            else
            {
                if(v_c[min(r, r+temp.first)][c] == false)
                {
                    v_c[min(r, r+temp.first)][c] = true;
                    answer++;
                }
            }
            r+=temp.first;
            c+=temp.second;
        }
        else
            continue;
    }
    return answer;
}
