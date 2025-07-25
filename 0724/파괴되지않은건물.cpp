#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    const int N = board.size();
    const int M = board[0].size();
    
    const int skillNum = skill.size();
    
    for(int skillIdx = 0; skillIdx < skillNum; ++skillIdx)
    {
        int r1 = skill[skillIdx][1];
        int c1 = skill[skillIdx][2];
        int r2 = skill[skillIdx][3];
        int c2 = skill[skillIdx][4];
        int degree = skill[skillIdx][5];
        
        if(skill[skillIdx][0] == 1)     // 공격
        {
            for(int rr1 = r1; rr1 <= r2; ++rr1)
            {
                for(int cc1 = c1; cc1 <= c2; ++cc1)
                {
                    board[rr1][cc1] -= degree;
                }
            }
        }
        
        else if(skill[skillIdx][0] == 2)     // 회복
        {
            for(int rr1 = r1; rr1 <= r2; ++rr1)
            {
                for(int cc1 = c1; cc1 <= c2; ++cc1)
                {
                    board[rr1][cc1] += degree;
                }
            }
        }
    }
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(board[i][j] > 0)
            {
                ++answer;
            }
        }
    }
    
    return answer;
}