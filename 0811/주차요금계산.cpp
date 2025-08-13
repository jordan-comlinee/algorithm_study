#include <string>
#include <vector>
#include <map>

using namespace std;

int toMinute(string timeStr)
{
    int h = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
    int m = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
    return h * 60 + m;
}

vector<string> splitSpace(string s)
{
    vector<string> tokens;
    string cur = "";
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            if (!cur.empty())
            {
                tokens.push_back(cur);
                cur = "";
            }
        }
        else
        {
            cur.push_back(s[i]);
        }
    }
    if (!cur.empty()) tokens.push_back(cur);
    return tokens;
}

int computeFee(int total, vector<int> fees)
{
    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    if (total <= baseTime)
    {
        return baseFee;
    }
    else
    {
        int over = total - baseTime;
        int units = (over + unitTime - 1) / unitTime;
        return baseFee + units * unitFee;
    }
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, int> inTime;
    map<string, int> totalTime;

    for (int i = 0; i < (int)records.size(); ++i)
    {
        vector<string> t = splitSpace(records[i]);
        int timeMin = toMinute(t[0]);
        string car = t[1];
        string typ = t[2];

        if (typ == "IN")
        {
            inTime[car] = timeMin;
        }
        else
        {
            int park = timeMin - inTime[car];
            totalTime[car] += park;
            inTime.erase(car);
        }
    }

    int endOfDay = toMinute("23:59");
    for (map<string, int>::iterator it = inTime.begin(); it != inTime.end(); ++it)
    {
        string car = it->first;
        int park = endOfDay - it->second;
        totalTime[car] += park;
    }

    for (map<string, int>::iterator it = totalTime.begin(); it != totalTime.end(); ++it)
    {
        int fee = computeFee(it->second, fees);
        answer.push_back(fee);
    }

    return answer;
}
