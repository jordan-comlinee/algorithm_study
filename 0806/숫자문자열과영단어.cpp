#include <string>
#include <vector>

#define ZERO 4
#define ONE 3
#define TWO 3
#define THREE 5
#define FOUR 4
#define FIVE 4
#define SIX 3
#define SEVEN 5
#define EIGHT 5
#define NINE 4

using namespace std;

int solution(string s) {
    int answer = 0;
    string answerS = "";    
    
    // z ? zero, size: 4
    // o ? one, size: 3
    // t ? size: 3 -> two, size: 5 -> three
    // f ? o -> four, i -> five
    // s ? size: 3 -> six, size: 5 -> seven
    // e ? eight, size: 5
    // n ? nine, size: 4
    
    int sSize = s.size();
    
    for(int idx = 0; idx < sSize;)
    {
        const char c = s[idx];
        switch(c)
        {
            case 'z':
                answerS += '0';
                idx += ZERO;
                break;
            case 'o':
                answerS += '1';
                idx += ONE;
                break;
            case 't':
                if(s[idx + 1] == 'w')
                {
                    answerS += '2';
                    idx += TWO;
                }
                else if(s[idx + 1] == 'h')
                {
                    answerS += '3';
                    idx += THREE;
                }
                break;
            case 'f':
                if(s[idx + 1] == 'o')
                {
                    answerS += '4';
                    idx += FOUR;
                }
                else if(s[idx + 1] == 'i')
                {
                    answerS += '5';
                    idx += FIVE;
                }
                break;
            case 's':
                if(s[idx + 1] == 'i')
                {
                    answerS += '6';
                    idx += SIX;
                }
                else if(s[idx + 1] == 'e')
                {
                    answerS += '7';
                    idx += SEVEN;
                }
                break;
            case 'e':
                answerS += '8';
                idx += EIGHT;
                break;
            case 'n':
                answerS += '9';
                idx += NINE;
                break;
            default:
                answerS += c;
                ++idx;
                break;
        }
    }
    
    answer = stoi(answerS);
    
    return answer;
}