#include <string>
#include <vector>
#include <iostream>

#define RT 0
#define CF 1
#define JM 2
#define AN 3

using namespace std;

vector<pair<int, int>> Personality;

string solution(vector<string> survey, vector<int> choices) {

    Personality.resize(4);
    string answer = "";

    for (int i = 0; i < survey.size(); ++i)
    {
        if (choices[i] == 4) continue;

        if (survey[i] == "RT")
        {
            if (choices[i] < 4)
            {
                Personality[RT].first += (4 - choices[i]);
            }
            else if (choices[i] > 4)
            {
                Personality[RT].second += (choices[i] - 4);
            }
        }
        if (survey[i] == "TR")
        {
            if (choices[i] < 4)
            {
                Personality[RT].first += (choices[i] - 4);
            }
            else if (choices[i] > 4)
            {
                Personality[RT].second += (4 - choices[i]);
            }
        }
        if (survey[i] == "CF")
        {
            if (choices[i] < 4)
            {
                Personality[CF].first += (4 - choices[i]);
            }
            else if (choices[i] > 4)
            {
                Personality[CF].second += (choices[i] - 4);
            }
        }
        if (survey[i] == "FC")
        {
            if (choices[i] < 4)
            {
                Personality[CF].first += (choices[i] - 4);
            }
            else if (choices[i] > 4)
            {
                Personality[CF].second += (4 - choices[i]);
            }
        }
        if (survey[i] == "JM")
        {
            if (choices[i] < 4)
            {
                Personality[JM].first += (4 - choices[i]);
            }
            else if (choices[i] > 4)
            {
                Personality[JM].second += (choices[i] - 4);
            }
        }
        if (survey[i] == "MJ")
        {
            if (choices[i] < 4)
            {
                Personality[JM].first += (choices[i] - 4);
            }
            else if (choices[i] > 4)
            {
                Personality[JM].second += (4 - choices[i]);
            }
        }
        if (survey[i] == "AN")
        {
            if (choices[i] < 4)
            {
                Personality[AN].first += (4 - choices[i]);
            }
            else if (choices[i] > 4)
            {
                Personality[AN].second += (choices[i] - 4);
            }
        }
        if (survey[i] == "NA")
        {
            if (choices[i] < 4)
            {
                Personality[AN].first += (choices[i] - 4);
            }
            else if (choices[i] > 4)
            {
                Personality[AN].second += (4 - choices[i]);
            }
        }
    }

    if (Personality[RT].first > Personality[RT].second)
    {
        answer.push_back('R');
    }
    else if (Personality[RT].first < Personality[RT].second)
    {
        answer.push_back('T');
    }
    else
    {
        answer.push_back('R');
    }


    if (Personality[CF].first > Personality[CF].second)
    {
        answer.push_back('C');
    }
    else if (Personality[CF].first < Personality[CF].second)
    {
        answer.push_back('F');
    }
    else
    {
        answer.push_back('C');
    }

    if (Personality[JM].first > Personality[JM].second)
    {
        answer.push_back('J');
    }
    else if (Personality[JM].first < Personality[JM].second)
    {
        answer.push_back('M');
    }
    else
    {
        answer.push_back('J');
    }

    if (Personality[AN].first > Personality[AN].second)
    {
        answer.push_back('A');
    }
    else if (Personality[AN].first < Personality[AN].second)
    {
        answer.push_back('N');
    }
    else
    {
        answer.push_back('A');
    }

    return answer;
}