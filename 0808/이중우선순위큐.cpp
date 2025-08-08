#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    // priority_queue<int> q;
    deque<int> dq;
    
    string token;
    
    for(const auto& s : operations)
    {
        bool flag = false;
        bool insertFlag = false;
        bool deleteFlag = false;
        bool maxDeleteFlag = false;
        bool minDeleteFlag = false;
        
        istringstream iss(s);    
        while(iss >> token)
        {
            if(flag)
            {
                int num = stoi(token);
                if(insertFlag)
                {                    
                    dq.push_back(num);
                    sort(dq.begin(), dq.end(), [](const int a, const int b)
                         {
                             return a > b;
                         });
                }
                else if(deleteFlag)
                {
                    if(num == 1)
                    {
                        if(!dq.empty())
                        {
                            dq.pop_front();
                        }                        
                    }
                    else if(num == -1)
                    {
                        if(!dq.empty())
                        {
                            dq.pop_back();
                        }
                    }
                }
            }            
            
            else
            {
                if(!flag && token == "I")
                {
                    flag = true;
                    insertFlag = true;
                }
                else if(!flag && token == "D")
                {
                    flag = true;
                    deleteFlag = true;
                }
            }           
        }
    }
    
    if(dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(dq.front());
        answer.push_back(dq.back());
    }
    
    return answer;
}