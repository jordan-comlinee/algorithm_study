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