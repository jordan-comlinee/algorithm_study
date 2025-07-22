#include <string>
#include <vector>

using namespace std;

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