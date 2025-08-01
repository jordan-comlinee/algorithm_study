#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canBo(int x, int y, const vector<vector<bool>>& bo, const vector<vector<bool>>& gidung)
{
    if((y == 0) || bo[x][y - 1] || gidung[x][y] || (x > 0 && gidung[x - 1][y]))     // 바닥 위, 기둥 위, 보 위
    {
        return true;                 // 바닥 위
    }
    
    return false;
}

bool canGidung(int x, int y, const vector<vector<bool>>& bo, const vector<vector<bool>>& gidung)
{
    if(bo[x][y - 1] || bo[x + 1][y - 1] || (x > 0 && gidung[x - 1][y] && gidung[x + 1][y]))     // 양 끝 기둥 위, 양쪽 보
    {
        return true;
    }
    
    return false;
}

bool canDelete(int n, const vector<vector<bool>>& bo, const vector<vector<bool>>& gidung)
{
    for(int x = 0; x <= n; ++x)
    {
        for(int y = 0; y <= n; ++y)
        {
            if((bo[x][y] && !canBo(x, y, bo, gidung)) || (gidung[x][y] && !canGidung(x, y, bo, gidung)))
            {
                return false;
            }        
        }
    }
    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    
    
    // 가로 좌표, 세롲 ㅘ표
    // 0: 기둥, 1: 보
    // 0: 삭제, 1: 설치
    
    /* 설치 조건 */
    // 기둥 조건: 바닥 위 || 보의 한쪽 끝 부분 || 다른 기둥 위
    // 보 저건: 한쪽 끝 부분이 기둥 위 }|| 양쪽 끝 부분이 다른 보와 동시에 연결
    
    vector<vector<bool>> bo(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> gidung(n + 1, vector<bool>(n + 1, false));
    
    for(const auto& frame : build_frame)
    {
        int x = frame[0];
        int y = frame[1];
        int type = frame[2]; // 0: 기둥, 1: 보
        int cmd  = frame[3]; // 0: 삭제, 1: 설치
        
        if(cmd == 1)    // 설치
        {
            if(type == 0)   // 기둥
            {
                if(canBo(x, y, bo, gidung))
                {
                    bo[x][y] = true;
                }
            }
            else    // 보
            {
                if(canGidung(x, y, bo, gidung))
                {
                    gidung[x][y] = true;
                }
            }
        }
        
        else    // 삭제
        {
            if(type == 0)
            {
                bo[x][y] = false;
            }
            else
            {
                gidung[x][y] = false;
            }
            
            if(!canDelete(n, bo, gidung))
            {
                if(type == 0)
                {
                    bo[x][y] = true;
                }
                else
                {
                    gidung[x][y] = true;
                }
            }
        }
    }
    
    for(int x = 0; x <= n; ++x)
    {
        for(int y = 0; y <= n; ++y)
        {
            if(bo[x][y])
            {
                answer.push_back({x, y, 0});
            }
            if(gidung[x][y])
            {
                answer.push_back({x, y, 1});
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}