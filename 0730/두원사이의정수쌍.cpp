#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {

    long long answer = 0;

    for (int x = 1; x <= r2; ++x)
    {

        long long maxY = (long long)(sqrt((long long)r2 * r2 - (long long)x * x));
        long long minY = 0;

        if (x < r1)
        {
            minY = (long long)ceil(sqrt((long long)r1 * r1 - (long long)x * x));
        }

        //x에 따른 1사분면 점의 개수 계산 기릿 x=0일때는 제외 (x 4배하기 위해서)

        answer += (maxY - minY + 1);

        //하지만 내부원에 있는 점은 빼주고, 중복으로 빼진 1개만큼 더하기
    }
    return answer * 4;

    //1사분면에서만 계산 했기 때문에 4배
}
