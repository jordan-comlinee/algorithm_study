#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long r1_num = 0;
    long long r2_num = 0;
    
    long long R1  = (long long)r1 * r1;
    long long R2  = (long long)r2 * r2;
    for(long long i = 1; i<r2; i++)
    {
        long long t = sqrtl(R2 - i*i);
        r2_num+=t;
    }
    r2_num*=4;
    r2_num+=(4*(long long)r2 + 1);
    
    for(long long i = 1; i < r1; i++)
    {
        long long t = sqrtl(R1 - i*i);
        if(t*t + i*i == R1)
            t--;
        r1_num+=t;
    }
    r1_num*=4;
    r1_num+=(4*(long long)(r1-1) + 1);
    
    return r2_num - r1_num;
}
