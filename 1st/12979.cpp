#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int antenaArea = 2 * w + 1;
    int prev = 0;

    for (const int station : stations)
    {
        int left = station - w;
        int noAntenaArea = left - prev - 1;
        if (noAntenaArea > 0)
        {
            answer += (int)ceil((double)noAntenaArea / antenaArea);
        }            

        prev = station + w;
    }

    if (prev < n)
    {
        int noAntenaArea = n - prev;
        answer += (int)ceil((double)noAntenaArea / antenaArea);
    }        

    return answer;
}
