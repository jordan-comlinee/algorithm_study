#include <string>
#include <vector>
#include <unordered_map>

#define VERY_DISAGREE 3
#define DISAGREE 2
#define LITTLE_DSAGREE 1
#define DONT_KNOW 0
#define LITTLE_AGREE 1
#define AGREE 2
#define VERY_AGREE 3

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char, int> um;
    um['R'] = 0;
    um['T'] = 0;
    um['C'] = 0;
    um['F'] = 0;
    um['J'] = 0;
    um['M'] = 0;
    um['A'] = 0;
    um['N'] = 0;
    
    const int surveySize = survey.size();
    
    for(int i = 0; i < surveySize; ++i)
    {
        const char disagreeType = survey[i][0];
        const char agreeType = survey[i][1];
        const int choice = choices[i];
        
        switch(choice)
        {
            case 1:
                um[disagreeType] += VERY_DISAGREE;
                break;
            case 2:
                um[disagreeType] += DISAGREE;
                break;
            case 3:
                um[disagreeType] += LITTLE_DSAGREE;
                break;
            case 4:
                break;
            case 5:
                um[agreeType] += LITTLE_AGREE;
                break;
            case 6:
                um[agreeType] += AGREE;
                break;
            case 7:
                um[agreeType] += VERY_AGREE;
                break;
        }
    }
    
    if(um['R'] >= um['T'])
    {
        answer += 'R';
    }
    else
    {
        answer += 'T';
    }
    
    if(um['C'] >= um['F'])
    {
        answer += 'C';
    }
    else
    {
        answer += 'F';
    }
    
    if(um['J'] >= um['M'])
    {
        answer += 'J';
    }
    else
    {
        answer += 'M';
    }
    
    if(um['A'] >= um['N'])
    {
        answer += 'A';
    }
    else
    {
        answer += 'N';
    }
    
    
    return answer;
}