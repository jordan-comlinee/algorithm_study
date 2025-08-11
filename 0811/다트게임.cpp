#include <string>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> scores;
    int idx = 0;
    int number = 0;
    while (idx < dartResult.size())
    {
        if (isdigit(dartResult[idx]))
        {
            scores.push_back(number);
            number = dartResult[idx] - '0';
            if (dartResult[idx] == '1' && dartResult[idx + 1] == '0')
            {
                ++idx;
                number = 10;
            }
        }
        switch (dartResult[idx])
        {
        case 'S':
            break;
        case 'D':
            number = pow(number, 2);
            break;
        case 'T':
            number = pow(number, 3);
            break;
        case '*':
            scores[scores.size() - 1] *= 2;
            number *= 2;
            break;
        case '#':
            number *= -1;
            break;
        default:
            break;
        }
        idx++;
    }
    scores.push_back(number);
    return accumulate(scores.begin(), scores.end(), 0);
}