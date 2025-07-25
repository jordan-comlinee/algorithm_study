#if 0
// soyoung
#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

const string yes = "Yes";
const string no = "No";

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    deque<string> one(cards1.begin(), cards1.end());
    deque<string> two(cards2.begin(), cards2.end());
    deque<string> dGoal(goal.begin(), goal.end());
    bool interrupt = false;
    while (!dGoal.empty())
    {
        string g = dGoal.front();
        dGoal.pop_front();
        if (g == one.front()) one.pop_front();
        else if (g == two.front()) two.pop_front();
        else return no;
    }
    return yes;
}
#endif
#if 0
// seongho
#include <string>
#include <vector>

using namespace std;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    // card1을 가리키는 idx1, card2를 가리키는 idx2
    int idx1 = 0, idx2 = 0;
    for(const auto& t : goal)
    {
        if(idx1 < cards1.size() && t == cards1[idx1])
            idx1++;
        else if(idx2 < cards2.size() && t == cards2[idx2])
            idx2++;
        else
            answer = "No";
    }
      return answer;
}
#endif
#if 0
// johoon
#include <string>
#include <vector>

using namespace std
bool backTracking(int idx, int c1, int c2, const vector<string>& cards1, const vector<string>& cards2, const vector<string>& goal)
{
    if(idx == goal.size())
    {
        return true;
    }
    
    if(c1 < cards1.size() && cards1[c1] == goal[idx])
    {
        if(backTracking(idx + 1, c1 + 1, c2, cards1, cards2, goal))
        {
            return true;
        }
    }
    
    if(c2 < cards2.size() && cards2[c2] == goal[idx])
    {
        if(backTracking(idx + 1, c1, c2 + 1, cards1, cards2, goal))
        {
            return true;
        }
    }
    
    return false;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    answer = backTracking(0, 0, 0, cards1, cards2, goal) ? "Yes" : "No";
    return answer;
}
#endif
