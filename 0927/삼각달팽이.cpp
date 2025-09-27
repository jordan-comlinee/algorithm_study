#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    answer.assign(sum, 0);
    
    int num = 1;
    for(int l = 0;;++l)
    {
        int length = n - 3 * l;
        if(length <= 0)
        {
            break;
        }
        
        int row = 2 * l - 1;
        int col = l;
        
        for(int i = 0; i < length; ++i)
        {
            ++row;
            int idx = row * (row + 1) / 2 + col;
            answer[idx] = num++;
        }
        
        for(int i = 0; i < length - 1; ++i)
        {
            ++col;
            int idx = row * (row + 1) / 2 + col;
            answer[idx] = num++;
        }

        for(int i = 0; i < length - 2; ++i)
        {
            --row;
            --col;
            int idx = row * (row + 1) / 2 + col;
            answer[idx] = num++;
        }
    }
    
    return answer;
}