#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

int toMin(const string& time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    const int baseTime = fees[0];
    const int baseFee  = fees[1];
    const int plusTime = fees[2];
    const int plusFee  = fees[3];
    const int maybeOut = 23 * 60 + 59;
    
    unordered_map<string, int> curCar;
    map<string, int> curCarTime;
    
    for(const string& record : records)
    {
        istringstream iss(record);
        string time, carNum, inOut;
        iss >> time >> carNum >> inOut;

        int t = toMin(time);
        if(inOut == "IN")
        {
            curCar[carNum] = t;
        }
        else
        {
            curCarTime[carNum] += t - curCar[carNum];
            curCar.erase(carNum);
        }
    }
    
    for(const auto& intime : curCar)
    {
        const string& car = intime.first;
        int it = intime.second;
        curCarTime[car] += maybeOut - it;
    }
    
    for(const auto& time : curCarTime)
    {
        int t = time.second;
        int fee = baseFee;
        if(t > baseTime)
        {
            int plusplusTime = t - baseTime;
            int good = (plusplusTime + plusTime - 1) / plusTime;
            fee += good * plusFee;
        }
        
        answer.push_back(fee);
    }
    
    return answer;
}