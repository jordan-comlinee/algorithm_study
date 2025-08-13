#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    #if 0
    
    vector<int> B sort -> 최대 승점 되게
    근데 A꺼 정렬 만져도 상관없는거 아닌가
    
    next_permu..
    근데 완탐은 하면 안될듯
    
    근데 완탐 해야한느거 아닌가
    sort 방법이 주용할듯?
    한번만 for문 돌리게
    
    방법 1. 각 팀 평균 내고 중간 사이즈 비교해서?
    방법 2. 내림차순 정렬하고 중간 인덱스 보고 팓난?
    
    
    if(A팀 점수 > B팀 점수)
    {
        ++A팀 점수            
    }
    else if(A팀 점수 < B팀 점수)
    {
        ++B팀 점수
    }
    else
    {
        아무것도 안함
    }
    #endif
    
    sort(A.begin(), A.end(), [](const int& a, const int& b)
         {
             return a > b;
         });
    sort(B.begin(), B.end(), [](const int& a, const int& b)
         {
             return a > b;
         });
    
    const int teamSize = A.size();
    int aIdx = teamSize - 1;
    int bIdx = teamSize - 1;
    
    while(aIdx >= 0 && bIdx >= 0)
    {
        if(B[bIdx] > A[aIdx])
        {
            ++answer;
            --aIdx;
            --bIdx;
        }
        else
        {
            --bIdx;
        }
    }
    
    return answer;
}