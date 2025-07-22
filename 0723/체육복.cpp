#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    vector<int> arr(n+2, 1);
    arr[0] = 0, arr[n+1] = 0;
    for(const auto& t :reserve)
        arr[t]++;
    for(const auto& t : lost)
        arr[t]--;
    
    for(int i = 1; i<=n; i++)
    {
        if(arr[i] > 0)
            continue;
        if(arr[i-1] == 2)
        {
            arr[i-1] = 1;
            arr[i] = 1;
        }
        else if(arr[i+1] == 2)
        {
            arr[i+1] = 1;
            arr[i] = 1;
        }
        else
        {
            
            answer--;
           continue;
        }
     
    }

    return answer;
}
