#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

vector<map<char, int>> maps = { {{'R', 0}, {'T', 0}}, {{'C', 0}, {'F', 0}}, {{'J', 0}, {'M', 0}}, {{'A', 0}, {'N', 0}} };

unordered_map<char, int> alphabet = { {'R', 0}, {'T', 0}, {'C', 1}, {'F', 1}, {'J', 2}, {'M', 2}, {'A', 3}, {'N', 3} };

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for (int i = 0; i < survey.size(); ++i)
    {
        char one = survey[i][0];
        char two = survey[i][1];
        int idx = alphabet[one];
        if (choices[i] < 4)
        {
            maps[idx][one] += 4 - choices[i];
        }
        else if (choices[i] > 4)
        {
            maps[idx][two] += choices[i] - 4;
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        char winner;
        int max = -1;
        for (auto [key, val] : maps[i])
        {
            if (max < val)
            {
                max = val;
                winner = key;
            }
        }
        answer += winner;
    }


    return answer;
}