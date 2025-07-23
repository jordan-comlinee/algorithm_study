// 틀린 버전

#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
    int ans = 0;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = min((i % 2 == 0 ? dp[i / 2] : dp[i / 2] + 1), dp[i - 1] + 1);
    }
    ans = dp[n];
    return ans;
}