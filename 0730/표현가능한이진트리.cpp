#include <string>
#include <vector>

using namespace std;
int isRight(int s, int e, vector<int>& arr)
{
    if(e == s)
        return arr[s];
    int mid = (e+s)/2;
    int a = isRight(s, mid-1, arr);
    int b = isRight(mid+1, e, arr);
    if(a == 2 || b == 2 || (arr[mid] == 0 && (a == 1 || b == 1)))
        return 2;
    else if(arr[mid] == 1)
        return 1;
    else
        return 0;
}
vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;
    for(auto& t :  numbers)
    {
        vector<int> temp;
        long long c = 1;
        long long idx = -1;
        while(true)
        {
            for(long long i = 0; i<c; i++)
            {
                idx++;
                temp.push_back(t%2);
                t/=2;
            }
            c*=2;
            if(t == 0)
                break;
        }
        int p = isRight(0, temp.size()-1, temp);
        if(p == 1)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}
