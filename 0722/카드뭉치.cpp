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