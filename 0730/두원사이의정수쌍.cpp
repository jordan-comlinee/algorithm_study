#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long count = 0;
    long long r1r1 = static_cast<long long>(r1) * r1;
    long long r2r2 = static_cast<long long>(r2) * r2;
    
    for(int x = 1; x <= r2; ++x)
    {
        long long x2 = static_cast<long long>(x) * x;
        long long maxY2 = r2r2 - x2;
        if(maxY2 < 1)
        {
            continue;
        }
        
        long long yMax = static_cast<long long>(sqrt(static_cast<double>(maxY2)));
        
        long long minY2 = r1r1 - x2;
        long long yMin;
        if(minY2 <= 0)
        {
            yMin = 1;
        }
        else
        {
            yMin = static_cast<long long>(ceil(sqrt(static_cast<double>(minY2))));
        }
        
        if(yMax >= yMin)
        {
            count += (yMax - yMin + 1);
        }
    }
    
    answer = count * 4;
    long long axisCount = static_cast<long long>(r2 - r1 + 1);
    answer += axisCount * 4;
    
    return answer;
}
