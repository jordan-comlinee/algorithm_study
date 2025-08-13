#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int tmp = 0;
    int prev = 0;
    for(int i = 0; i<dartResult.size(); i++)
    {
        if(dartResult[i] == '1')
        {
            prev = tmp;
            answer+=tmp;
            if(dartResult[i+1] == '0')
            {
                tmp = 10;
                i++;
            }
            else
                tmp = 1;
            continue;
        }
        else if('1'<dartResult[i] && dartResult[i] <= '9' || dartResult[i] == '0')
        {
            prev = tmp;
            answer+=tmp;
            tmp = dartResult[i] - '0';
            continue;
        }
        else if(dartResult[i] == 'S')
        {
            continue;
        }
        else if(dartResult[i] == 'D')
        {
            tmp=tmp*tmp;
        }
        else if(dartResult[i] == 'T')
        {
            tmp = tmp*tmp*tmp;
        }
        else if(dartResult[i] == '*')
        {
            answer += prev;
            tmp *= 2;
        }
        else
        {
            tmp *= -1;
        }
    }
    answer+=tmp;
    return answer;
}
