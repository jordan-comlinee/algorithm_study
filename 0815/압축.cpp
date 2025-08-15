#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;
    m["A"] = 1;
    m["B"] = 2;
    m["C"] = 3;
    m["D"] = 4;
    m["E"] = 5;
    m["F"] = 6;
    m["G"] = 7;
    m["H"] = 8;
    m["I"] = 9;
    m["J"] = 10;
    m["K"] = 11;
    m["L"] = 12;
    m["M"] = 13;
    m["N"] = 14;
    m["O"] = 15;
    m["P"] = 16;
    m["Q"] = 17;
    m["R"] = 18;
    m["S"] = 19;
    m["T"] = 20;
    m["U"] = 21;
    m["V"] = 22;
    m["W"] = 23;
    m["X"] = 24;
    m["Y"] = 25;
    m["Z"] = 26;
    int now = 27;
    for(int i = 0; i < msg.size(); i++)
    {
        string temp = "";
        temp+=msg[i];
        int cnt = 1;
        while(i+cnt<msg.size())
        {
            string t = temp + msg[i+cnt];
            if(m[t])
            {
                temp = t;
                cnt++;
                continue;
            }
            else
            {
                answer.push_back(m[temp]);
                m[t] = now;
                now++;
                break;
            }   
        }
        if(i+cnt == msg.size())
        {
            answer.push_back(m[temp]);
        }
        i+=(cnt - 1);
    }
    return answer;
}
