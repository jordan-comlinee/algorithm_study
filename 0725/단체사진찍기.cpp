#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(char op, int n, int dis)
{
    if(op == '=')
    {
        if(n == dis)
            return true;
        else
            return false;
    }
    else if(op == '<')
    {
        if(dis < n)
            return true;
        else
            return false;
    }
    else
    {
        if(dis > n)
            return true;
        else
            return false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string od = "ACFJMNRT";
    do{
        bool p = false;
        for(int i = 0; i<n; i++)
        {
            string d = data[i];
            char s = d[0];
            char e = d[2];
            char op = d[3];
            char n = d[4];
            int s_od = od.find(s);
            int e_od = od.find(e);
            int dis = abs(s_od - e_od);
            dis--;
            int nn = n - '0';
            if(!check(op, nn, dis))
            {
                p = true;
                break;
            }
        }
        if(!p)
            answer++;
    }while(next_permutation(od.begin(), od.end()));
    return answer;
}