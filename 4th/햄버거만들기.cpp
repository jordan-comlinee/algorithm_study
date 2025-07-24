#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    // 2: 야채 1: 빵, 3: 고기
    // 1231
    int ingredientLength = ingredient.size();
    vector<int> stk;
    
    for(const int& i : ingredient)
    {
        stk.emplace_back(i);
        
        int stkLen = stk.size();
        
        if(stkLen >= 4)
        {
            if(stk[stkLen - 4] == 1 && stk[stkLen - 3] == 2 && stk[stkLen - 2] == 3 && stk[stkLen - 1] == 1)
            {
                for(int i = 0; i < 4; ++i)
                {
                    stk.pop_back();
                }
                ++answer;
            }
        }
        
    }
    
    return answer;
}