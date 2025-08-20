#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> m;
    
    for(int i = 0; i < survey.size(); i++)
    {
        int temp = choices[i];
        if(temp == 4)
            continue;
        else if(choices[i]<4)
            m[survey[i][0]] += (4-temp);
        else
            m[survey[i][1]] += (temp-4);
    }
    
    if(m['R']>=m['T'])
        answer+="R";
    else
        answer+="T";
    if(m['C']>=m['F'])
        answer+="C";
    else
        answer+="F";
    if(m['J']>=m['M'])
        answer+="J";
    else
        answer+="M";
    if(m['A']>=m['N'])
        answer+="A";
    else
        answer+="N";
    return answer;
}
