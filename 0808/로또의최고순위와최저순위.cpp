#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zeroNum = 0;
    const int lottosSize = lottos.size();
    const int win_numsSize = win_nums.size();
    
    
    int maxNum = 0;
    int minNum = 0;
    int matchNum = 0;
    
    sort(lottos.begin(), lottos.end(), [](const int a, const int b)
         {
             return a > b;
         });
    
    sort(win_nums.begin(), win_nums.end(), [](const int a, const int b)
         {
             return a > b;
         });
    
    for(const int& lotto : lottos)
    {
        if(!lotto)
        {
            ++zeroNum;
        }
    }
    
    int nLottosIdx = 0;
    for(int win_numsIdx = 0; win_numsIdx < win_numsSize; ++win_numsIdx)
    {
        for(int lottosIdx = 0; lottosIdx < lottosSize; ++lottosIdx)
        {
            if(lottos[lottosIdx] == win_nums[win_numsIdx])
            {                
                ++matchNum;
                break;
            }
        }
    }
    
    cout << matchNum << endl;
    maxNum = matchNum + zeroNum;
    cout << maxNum << endl;
    minNum = matchNum;
    
    int maxPrize = (maxNum >= 2) ? (7 - maxNum) : 6;
    int minPrize = (minNum >= 2) ? (7 - minNum) : 6;
    answer.push_back(maxPrize);
    answer.push_back(minPrize);
    
    // answer.push_back(7 - maxNum);
    // if(7 - minNum > 5)
    // {
    //     answer.push_back(6);
    // }
    // else
    // {
    //     answer.push_back(7 - minNum);
    // }
        
    return answer;
}