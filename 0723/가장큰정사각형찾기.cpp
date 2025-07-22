#include <iostream>
#include<vector>
using namespace std;

int bfs()
{
    
}

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    
    const int ySize = board.size();
    const int xSize = board[0].size();
    
    int rLen  = 0;
    int rArea = 0;

    for(int y = 0; y < ySize; ++y)
    {
        for(int x = 0; x < xSize; ++x)
        {
            if(board[y][x] == 0)
            {
                continue;
            }
            
            int maxSide = min(xSize - x, ySize - y);

            for(int side = rLen + 1; side <= maxSide; ++side)
            {
                bool ok = true;
                
                for(int j = 0; j < side; ++j)
                {
                    if(board[y + side - 1][x + j] == 0)
                    {
                        ok = false;
                        break;
                    }
                }
                
                if(!ok)
                {
                    break;
                }

                for(int i = 0; i < side - 1; ++i)
                {
                    if(board[y + i][x + side - 1] == 0)
                    {
                        ok = false;
                        break;
                    }
                }
                if(!ok)
                {
                    break;
                }

                rLen = side;
            }
        }
    }

    rArea = rLen * rLen;
    return rArea;
}