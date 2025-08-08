#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });
    int cp = routes[0][0] - 1;
    for (auto r : routes)
    {
        if (cp < r[0])
        {
            cp = r[1];
            answer++;
        }
        //answer++;
        //cout << r[0] << " " << r[1] << endl;
    }
    return answer;
}