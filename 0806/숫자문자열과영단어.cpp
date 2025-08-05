#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
using namespace std;

int solution(string s) {
    int answer = 0;
    int idx = 0;
    unordered_map<string, pair<int, int>> num{ {"ze", {0, 4}}, {"on", {1, 3}}, {"tw", {2, 3}}, {"th", {3, 5}}, {"fo", {4, 4}}, {"fi", {5, 4}}, {"si", {6, 3}}, {"se", {7, 5}}, {"ei", {8, 5}}, {"ni", {9, 4}} };
    while (idx < s.size())
    {
        if (isdigit(s[idx]))
        {
            answer *= 10;
            answer += s[idx] - '0';
            idx++;
        }
        else
        {
            //cout << s.substr(idx, 2) << endl;
            if (num.find(s.substr(idx, 2)) != num.end())
            {
                auto [number, size] = num[s.substr(idx, 2)];
                answer *= 10;
                answer += number;
                idx += size;
            }
        }

    }
    return answer;
}