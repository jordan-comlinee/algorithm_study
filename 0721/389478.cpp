#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    int k = 2 * (w - (num % w == 0 ? w : num % w)) + 1;
    while (true)
    {
        num += k;
        if (num > n) break;
        k = 2 * w - k;
        answer++;
    }
    return answer;
}