#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> u_find(100, -1);

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a[2] < b[2];
}

int find(int n)
{
    if(u_find[n] == -1)
        return n;
    u_find[n] = find(u_find[n]);
    return u_find[n];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), comp);
    for(const auto& t : costs)
    {
        int a_par = find(t[0]);
        int b_par = find(t[1]);
        if(a_par == b_par)
            continue;

        u_find[a_par] = b_par;
        answer+= t[2];
    }
    return answer;
}
