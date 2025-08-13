#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> res;
    unordered_map<string, int> park;
    for(const auto& t : records)
    {
        string type = t.substr(11);
        string car_num = t.substr(6, 4);
        string hour = t.substr(0, 2);
        string min = t.substr(3, 2);
        int h = stoi(hour);
        int m = stoi(min);
        m += (h*60);
        if(type == "IN")
        {
            park[car_num] = m+1;
        }
        else if(type == "OUT")
        {
            res[car_num] += m+1 - park[car_num];
            park[car_num] = 0;
        }
    }
    int m = 23*60 + 59;
    for(const auto& t : park)
    {
        if(t.second)
        {
            res[t.first] += m+1-t.second;
        }
    }
    for(const auto& t : res)
    {
        int price = fees[1];
        if(t.second - fees[0] > 0)
        {
            int slot_c = (t.second - fees[0])/fees[2];
            if((t.second - fees[0])%fees[2])
                slot_c++;
            price+=(slot_c*fees[3]);
        }
        answer.push_back(price);
    }
    return answer;
}
