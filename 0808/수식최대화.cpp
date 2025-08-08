#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

long long calc(const long long a, const long long b, const char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return 0;            
    }
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<char> operatorList;
    vector<long long> operandList;
    string operand_ = "";
    for(const char& c : expression)
    {
        if(c == '+' || c == '-' || c == '*')
        {
            operatorList.push_back(c);
            long long num = stoll(operand_);
            operandList.push_back(num);
            operand_ = "";
        }
        else
        {
            operand_ += c;
        }
    }
    
    if (!operand_.empty())
    {
        long long num = stoll(operand_);
        operandList.push_back(num);
    }
    
    const int operandListSize = operandList.size();
    const int operatorListSize = operandListSize - 1;
    vector<char> comb = { '+', '-', '*' };
    sort(comb.begin(), comb.end());
    
    do
    {
        vector<long long> num = operandList;
        vector<char> copyOperatorList = operatorList;

        for(const char c : comb)
        {
            int i = 0;
            while (i < copyOperatorList.size())
            {
                if (copyOperatorList[i] == c)
                {
                    long long value = calc(num[i], num[i + 1], c);
                    num[i] = value;
                    num.erase(num.begin() + i + 1);
                    copyOperatorList.erase(copyOperatorList.begin() + i);
                }
                else
                {
                    ++i;
                }
            }
        }

        answer = max(answer, llabs(num[0]));
    } while(next_permutation(comb.begin(), comb.end()));
    
    return answer;
}