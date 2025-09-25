#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(std::vector<int> a) {
    int answer = 0;
    
    const int aSize = a.size();
    
    if(aSize % 2)
    {
        return 0;
    }
    
    vector<int> cnt(aSize, 0);
    for(int idx : a)
    {
        ++cnt[idx];
    }
    
    for(int c = 0; c < aSize; ++c)
    {
        if(cnt[c] == 0)
        {
            continue;
        }
        
        int pair = 0;
        for(int idx = 0; idx < aSize; ++idx)
        {
            if((a[idx] != a[idx + 1]) && (a[idx] == c || a[idx + 1] == c))
            {
                ++pair;
                idx += 2;
            }
            else
            {
                ++idx;
            }
        }
        
        answer = max(answer, pair * 2);
    }
    
    return answer;
}