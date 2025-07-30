#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (int x = 1; x <= r2; ++x) {
        int maxY = floor(sqrt(1LL * r2 * r2 - 1LL * x * x));
        int minY = ceil(sqrt(max(0LL, 1LL * r1 * r1 - 1LL * x * x)));
        answer += maxY - minY + 1;
    }
    return answer * 4;
}