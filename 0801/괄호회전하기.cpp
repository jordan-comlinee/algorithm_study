#include <string>
#include <vector>
#include <deque>

using namespace std;

bool isMatch(const string& str)
{
    vector<char> stk;
    
    for(const char& c : str)
    {
        if(c == '(' || c == '[' || c == '{')
        {
            stk.push_back(c);
        }
        
        else    // 닫는거
        {            
            if(stk.empty())
            {
                return false;
            }
            
            char cc = stk.back();
            
            if((c == ')' && cc != '(') || (c == ']' && cc != '[') || (c == '}' && cc != '{'))
            {
                return false;
            }
            stk.pop_back();
        }
    }
    return true;
}


int solution(string s) {
    int answer = 0;
    
    const int stringSize = s.size();
    deque<char> dq(s.begin(), s.end());
    
    bool isSmall = false;
    bool isMiddle = false;
    bool isBig = false;
    
    const int maxIdx = stringSize - 1;
    
    for(int i = 0; i < stringSize; ++i) // 
    {
        string s(dq.begin(), dq.end());
        
        if(isMatch(s))
        {
            ++answer;
        }

        char front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }    
        
    return answer;
}