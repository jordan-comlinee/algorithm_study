#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string a = "";
    set<int> set;
    for (auto st : s)
    {
        if (0 <= st - '0' && st - '0' <= 9)
        {
            cout << st << endl;
            a += st;
        }
        else
        {
            set.insert(stoi(a));
        }
    }
    return answer;
}