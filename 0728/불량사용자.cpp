#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check_match(string user, string ban)
{
    if (user.size() != ban.size())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < user.size(); ++i)
        {
            if (ban[i] == '*') {
                continue;
            }
            else {
                if (ban[i] != user[i]) return false;
            }
        }
        return true;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {

    int answer = 0;

    //다못풀음
    return answer;
}