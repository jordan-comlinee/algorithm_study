#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> f_rate;
    vector<int> s;
    s.assign(N+2, 0);
    for(int i=0; i<stages.size(); i++)
    {
        s[stages[i]]++;
    }
    int sum = s[N+1];
    for(int i=N; i>=1; i--)
    {
        if(!s[i])
        {
            f_rate.push_back({i, 0});
            continue;
        }
        sum+=s[i];
        f_rate.push_back({i, (double)s[i]/(double)sum});
    }
    sort(f_rate.begin(), f_rate.end(), [](const pair<int, double>& a, const pair<int, double>& b){if(a.second == b.second)
                return a.first<b.first;
        return a.second>b.second;});
    for(int i =0; i<f_rate.size(); i++)
        answer.push_back(f_rate[i].first);
    return answer;
}