#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#define DEF_TIME 0
#define DEF_FEE  1
#define PER_TIME 2
#define PER_FEE  3
using namespace std;
int carRecord[10000];
const int maxTime = 23 * 60 + 59;

int htom(string time)
{
    //cout << stoi(time.substr(0, 2)) << " " << stoi(time.substr(3, 2)) << endl;
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int calcTime(const vector<int>& fees, int totalTime) {
    if (totalTime <= fees[DEF_TIME]) return fees[DEF_FEE];
    int extraTime = totalTime - fees[DEF_TIME];
    int unitCount = ceil((double)extraTime / fees[PER_TIME]);
    return fees[DEF_FEE] + unitCount * fees[PER_FEE];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> parkingLot;
    map<int, int> fee;
    for (auto record : records)
    {
        int carNum = stoi(record.substr(6, 4));
        string LOG = record.substr(11, 1);
        int time = htom(record);
        if (LOG == "O" && parkingLot.find(carNum) != parkingLot.end())
        {
            if (fee.find(carNum) == fee.end())
            {
                fee.insert({ carNum, 0 });
            }
            fee[carNum] += (time - parkingLot[carNum]);
            parkingLot.erase(carNum);
        }
        else
        {
            parkingLot.insert({ carNum, time });
        }
    }
    for (auto lot : parkingLot)
    {
        if (fee.find(lot.first) == fee.end()) fee.insert({ lot.first, 0 });
        fee[lot.first] += (maxTime - lot.second);
    }
    for (auto f : fee)
    {
        cout << f.first << " " << f.second << " : ";
        answer.push_back(calcTime(fees, f.second));
    }
    return answer;
}