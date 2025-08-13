#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    int f = 0, l = B.size()-1;
    for(const auto& t : A)
    {
        if(t < B[f])
        {
            f++;
            answer++;
        }
        else
        {
            l--;
        }
    }
    return answer;
}
