#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int winCount = 0;
    int i = 0;
    int j = 0;
    int n = (int)A.size();

    while (i < n && j < n)
    {
        if (B[j] > A[i])
        {
            winCount++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return winCount;
}