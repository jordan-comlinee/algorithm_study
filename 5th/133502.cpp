#include <string>
#include <vector>
#include <deque>
using namespace std;
// 빵 - 야채 - 고기 -빵 순서
// 1: 빵, 2: 야채, 3: 고기
int solution(vector<int> ingredient) {
    int answer = 0;
    deque<int> d;
    if(ingredient.size() < 4)
        return 0;
    
    for(int i = 0; i<ingredient.size(); i++)
    {
        if(d.size() < 3)
            d.push_back(ingredient[i]);
        else
        {
            if(ingredient[i] != 1)
                d.push_back(ingredient[i]);
            else if(d.at(d.size()-1) == 3 && d.at(d.size()-2) == 2 && d.at(d.size()-3) == 1)
            {
                d.pop_back();
                d.pop_back();
                d.pop_back();
                answer++;
            }
            else
                d.push_back(ingredient[i]);
        }
    }
    return answer;
}
