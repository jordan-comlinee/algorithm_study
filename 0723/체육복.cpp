#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> attendees(n + 2, 0);
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 1; i < n + 1; ++i)
    {
        attendees[i] = 1;
    }
    for (auto l : lost)
    {
        attendees[l] = 0;
    }
    for (auto r : reserve)
    {
        attendees[r]++;
    }
    for (auto l : lost)
    {
        if (attendees[l] == 0)
        {
            if (attendees[l - 1] > 1)
            {
                attendees[l - 1]--;
                attendees[l]++;
            }
            else if (attendees[l + 1] > 1)
            {
                attendees[l + 1]--;
                attendees[l]++;
            }
        }

    }
    for (auto a : attendees)
    {
        if (a > 0) answer++;
    }
    return answer;
}