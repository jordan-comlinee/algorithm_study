#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> three;
    while(n / 3)
    {
        three.emplace_back(n % 3);
        n /= 3;
    }
    
    three.emplace_back(n % 3);
    
    int N = three.size() - 1;
    int idx = 0;
    for(int i = N; i >= 0; --i)
    {
        answer += pow(3, i) * three[idx];
        ++idx;
    }
    
    return answer;
}