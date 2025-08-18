#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> mScore;
    
    const int limit = k;
    int curLimit = 0;
    
    for(const int& s : score)
    {
        if(curLimit == limit)
        {
            const auto it = min_element(mScore.begin(), mScore.end());
            if(*it < s)
            {
                mScore.erase(it);
                mScore.push_back(s);
                answer.push_back(*min_element(mScore.begin(), mScore.end()));
            }
            else
            {
                answer.push_back(*min_element(mScore.begin(), mScore.end()));
            }
        }
        else
        {
            mScore.push_back(s);
            answer.push_back(*min_element(mScore.begin(), mScore.end()));
            ++curLimit;
        }
    }
    
    return answer;
}