#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int solution(string dartResult)
{
    vector<int> scores;
    scores.reserve(3);

    for (int i = 0; i < dartResult.size(); )
    {
        int val = dartResult[i] - '0';
        if (i + 1 < dartResult.size() && isdigit(dartResult[i + 1]))
        {
            val = val * 10 + (dartResult[i + 1] - '0');
            i += 2;
        }
        else
        {
            i += 1;
        }

        char bonus = dartResult[i++];
        if (bonus == 'D') val = pow(val, 2);
        else if (bonus == 'T') val = pow(val, 3);

        if (i < dartResult.size() && (dartResult[i] == '*' || dartResult[i] == '#'))
        {
            if (dartResult[i] == '*')
            {
                val *= 2;
                if (!scores.empty()) scores.back() *= 2;
            }
            else
            {
                val *= -1;
            }
            i += 1;
        }

        scores.push_back(val);
    }

    int answer = 0;
    for (int s : scores) answer += s;
    return answer;
}