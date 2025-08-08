#if 0
// seongho
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
#if 0
// jihoon
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;
    
    while(!((n / 2) == 1))
    {
        ans += (n % 2);
        n /= 2;
    }
    ans += (n % 2);
    
    return ans;
}
#endif
