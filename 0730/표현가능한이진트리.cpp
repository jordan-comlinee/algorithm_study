#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;    
    
    for(const long long& number : numbers)
    {
        long long curNum = number;
        vector<int> bin;
        while(curNum > 0)
        {
            bin.emplace_back(curNum % 2);
            // cout << curNum %2 << " ";
            curNum /= 2;
        }
        reverse(bin.begin(), bin.end());
        // cout << "\n";
        
        int binSize = bin.size();
        int binTreeSize = 1;
        for(;binTreeSize < binSize; binTreeSize = (2 * binTreeSize) + 1);

        cout << "binSize: " << binSize << "\n";
        cout << "binTreeSize: " << binTreeSize << "\n";
    }
    
    
    
    return answer;
}