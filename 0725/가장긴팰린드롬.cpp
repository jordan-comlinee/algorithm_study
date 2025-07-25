#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    for(int i = 0; i < s.size(); i++)
    {
        int n = 1;
        while(i-n>=0 && i+n<s.size())
        {
            if(s[i-n] == s[i+n])
                n++;
            else
                break;
        }
        if((n-1)*2+1 > answer)
            answer = (n-1)*2+1;
        n = 0;
        int t = i, j = i+1;
        while(t>=0 && j<s.size())
        {
            if(s[t] == s[j])
            {
                t--;
                j++;
                n+=2;
            }
            else
                break;
        }
        if(n > answer)
            answer = n;
    }
    
    return answer;
}