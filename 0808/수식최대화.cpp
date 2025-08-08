#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long solution(string expression) {
    long long answer = -21000000000;
    vector<long long> num;
    vector<char> exp;
    int idx = 0;
    string temp = "";
    unordered_map<char, int> m;
    while(idx<expression.size())
    {
        char t = expression[idx];
        if(t=='*' || t=='-' || t=='+')
        {
            m[t] = 1;
            if(temp.size())
            {
                num.push_back(stoll(temp));
                temp = "";
            }
            exp.push_back(t);
        }
        else
        {
            temp+=t;
        }
        idx++;
    }
    num.push_back(stoll(temp));
    
    vector<char> exp_rate;
    if(m['*']) exp_rate.push_back('*');
    if(m['+']) exp_rate.push_back('+');
    if(m['-']) exp_rate.push_back('-');
    
    do {
        vector<long long> t_num(num);
        vector<char> t_exp(exp);
        for(int i = 0; i<exp_rate.size(); i++)
        {
            vector<long long> new_num;
            vector<char> new_exp;
            for(int j = 0; j<t_exp.size(); j++)
            {
                if(t_exp[j] == exp_rate[i])
                {
                    if(t_exp[j]=='*')
                        t_num[j+1] = t_num[j] * t_num[j+1];
                    else if(t_exp[j]=='+')
                        t_num[j+1] = t_num[j] + t_num[j+1];
                    else
                        t_num[j+1] = t_num[j] - t_num[j+1];
                }
                else
                {
                    new_exp.push_back(t_exp[j]);
                    new_num.push_back(t_num[j]);
                }
            }
            new_num.push_back(t_num[t_num.size()-1]);
            t_exp = new_exp;
            t_num = new_num;
        }
        answer = max(answer, abs(t_num[0]));
    } while(next_permutation(exp_rate.begin(), exp_rate.end()));
    return answer;
}
