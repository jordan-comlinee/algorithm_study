#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    string answer = "";
    string temp = "";

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            answer += s[i];
        }
        else
        {
            temp += s[i];
        }
        if (temp.size() >= 3)
        {
            int startsize = answer.size();

            if (temp == "zero") answer += '0';
            if (temp == "one") answer += '1';
            if (temp == "two") answer += '2';
            if (temp == "three") answer += '3';
            if (temp == "four") answer += '4';
            if (temp == "five") answer += '5';
            if (temp == "six") answer += '6';
            if (temp == "seven") answer += '7';
            if (temp == "eight") answer += '8';
            if (temp == "nine") answer += '9';

            int endsize = answer.size();

            if (startsize - endsize) temp = "";
        }
    }
    return stoi(answer);
}