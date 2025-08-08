#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckString(string s, vector<string> v) {

    for (int i = 0; i < v.size(); ++i) {

        if (v[i] == s) return true;
    }
    return false;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

    vector<string> card1 = cards1;
    vector<string> card2 = cards2;

    for (int i = 0; i < goal.size(); ++i)
    {
        if (CheckString(goal[i], card1))
        {
            if (card1.front() != goal[i])
            {
                return "No";
            }
            card1.erase(card1.begin());
        }
        else if (CheckString(goal[i], card2))
        {
            if (card2.front() != goal[i])
            {
                return "No";
            }
            card2.erase(card2.begin());
        }
    }
    return "Yes";
}