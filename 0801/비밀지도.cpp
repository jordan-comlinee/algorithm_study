#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, "");
    
    vector<vector<int>> arr1Map(n, vector<int>(n, 0));
    vector<vector<int>> arr2Map(n, vector<int>(n, 0));
    
    for(int idx = 0; idx < n; ++idx)
    {
        int num1 = arr1[idx];
        for(int bit = n - 1; bit >= 0; --bit)
        {
            arr1Map[idx][bit] = num1 % 2;
            num1 /= 2;
        }
    }
    
    for(int idx = 0; idx < n; ++idx)
    {
        int num2 = arr2[idx];
        for(int bit = n - 1; bit >= 0; --bit)
        {
            arr2Map[idx][bit] = num2 % 2;
            num2 /= 2;
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(arr1Map[i][j] || arr2Map[i][j])
            {
                answer[i] += "#";
            }
            else
            {
                answer[i] += " ";
            }
        }
    }
    
    return answer;
}