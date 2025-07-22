#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> b;
vector<vector<bool>> v;
vector<vector<int>> arr;

int N, M;
int dp(int r, int c)
{
    if(r>=N || c>=M)
        return 0;
    if(b[r][c]==0)
        return 0;
    int num1;
    if(v[r+1][c]==false)
        num1 = dp(r+1,c);
    else
        num1 = arr[r+1][c];
    if(num1 == 0)
    {
        v[r][c] = true;
        arr[r][c] = 1;
        return 1;
    }
    int num2;
    if(v[r][c+1]==false)
        num2 = dp(r, c+1);
    else
        num2 = arr[r][c+1];
    if(num2==0)
    {
        v[r][c] = true;
        arr[r][c] = 1;
        return 1;
    }
    int num3;
    if(v[r+1][c+1]==false)
        num3 = dp(r+1, c+1);
    else
        num3 = arr[r+1][c+1];
    if(num3==0)
    {
        v[r][c] = true;
        arr[r][c] = 1;
        return 1;
    }
    int res = min(num1, num2);
    res = min(res, num3);
    v[r][c] = true;
    arr[r][c] = res+1;
    return 1+res;
}
int solution(vector<vector<int>> board)
{
    int answer = 0;
    N = board.size();
    M = board[0].size();
    b.resize(N, vector<int>(M, 0));
    v.resize(N+2, vector<bool>(M+2, false));
    arr.resize(N, vector<int>(M, 0));

    b = board;
    for(int i = 0; i<N; i++)
    {
        for(int j =0; j<M; j++)
        {
            int t = dp(i, j);
            if(t>answer)
                answer = t;
                
        }
    }

    return answer*answer;
}
