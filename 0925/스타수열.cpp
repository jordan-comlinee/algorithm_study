#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(std::vector<int> a) {
    int answer = 0;
    vector<int> arr(a.size()+1, 0);
    for(const auto& t : a)
        arr[t]++;
    int M = 0;
    for(int i = 0; i<a.size()+1; i++)
        if(arr[i] > arr[M])
            M = i;
    bool para1 = false;
    bool para2 = false;
    for(const auto& t : a)
    {
        if(t == M)
            para1 = true;
        if(t != M)
            para2 = true;
        if(para1 == true && para2 == true)
        {
            answer+=2;
            para1 = false;
            para2 = false;
        }
            
    }
    return answer;
}