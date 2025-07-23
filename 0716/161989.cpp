#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int isPainted = 0;
    for (auto sec : section)
    {
        if (isPainted < sec)
        {
            answer++;
            isPainted = sec + m - 1;
        }
    }
    return answer;
}