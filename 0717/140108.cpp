#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int same = 0, diff = 0;
    char first = s[0];

    for (int i = 0; i < s.size(); ++i) {
        if (same == 0) {
            first = s[i];
            ++same;
            continue;
        }

        if (s[i] == first) ++same;
        else ++diff;

        if (same == diff) {
            ++answer;
            same = diff = 0;
        }
    }
    if (same != 0 || diff != 0) ++answer;
    return answer;
}
