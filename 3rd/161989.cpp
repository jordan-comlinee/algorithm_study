#if 0
// seongho
#include <string>
#include <vector>
#include <iostream>

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
#endif
#if 0
// jihoon
#include <string>
#include <vector>
#include <iostream>
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int sectionSize = section.size();
    if(!sectionSize)
    {
        return 0;
    }
        
    int endSectionP = 0;
    for(int idx = 0; idx < sectionSize; ++idx)
    {
        int startSectionP = section[idx];        
        
        if(section[idx] <= endSectionP)
        {
            continue;
        }
        
        endSectionP = section[idx] + m - 1;
        ++answer;
    }
    
    return answer;
}
#endif
