#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    if(n==1)
        return 1;
    while(true)
    {
        if(n%2)
        {
            ans++;
            n--;
        }

        n/=2;
        
        if(n<=1)
            break;
    }
    ans++;
    return ans;
}
~

~

