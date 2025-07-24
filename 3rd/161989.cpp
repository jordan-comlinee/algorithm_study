#include <string>
#include <vector>
#include <iostream>

using namespace std;

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