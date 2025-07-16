#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int temp_point = -1;
    for(const auto& t : section)
    {
        if(temp_point < t)
        {
            answer++;
            temp_point = t+m-1;
        }
        
    }
    return answer;
}
