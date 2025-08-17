#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int aWeak = A.size() - 1;
    int aStrong = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (B[i] > A[aStrong])
        {
            aStrong++;
            answer++;
        }
        else
            aWeak--;
    }
    return answer;
}