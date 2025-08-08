#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// � 蹂瑜 � 寃쎌 ⑥ 댁 珥湲고 肄瑜 瑗 깊댁＜몄.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    const int friendNum = 8;
    string kakaoFriends = "ACFJMNRT";
    const int conditionNum = data.size();
    
    do
    {
        bool isGood = true;
        for(const auto& d : data)
        {
            char A = d[0];
            char B = d[2];
            char condition = d[3];
            int limit = d[4] - '0';

            int AIdx = kakaoFriends.find(A);
            int BIdx = kakaoFriends.find(B);
            int gap = abs(AIdx - BIdx) - 1;

            if(condition == '=')
            {
                if(gap != limit)
                {
                    isGood = false;
                    break;
                }
            }
            else if(condition == '<')
            {
                if(gap >= limit)
                {
                    isGood = false;
                    break;
                }
            }
            else if(condition == '>')
            {
                if(gap <= limit)
                {
                    isGood = false;
                    break;
                }
            }
        }
        if(isGood)
        {
            ++answer;
        }
    }while(next_permutation(kakaoFriends.begin(), kakaoFriends.end()));
    return answer;
}