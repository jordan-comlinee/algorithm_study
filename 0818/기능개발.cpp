#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int cnt = 0;
    queue<int> pq;
    queue<int> sq;

    for (int i = 0; i < progresses.size(); ++i)
    {
        pq.push(progresses[i]);
        sq.push(speeds[i]);
    }

    while (!pq.empty())
    {
        if (pq.front() + sq.front() * day >= 100)
        {
            pq.pop();
            sq.pop();
            cnt++;
        }
        else
        {
            if (cnt >= 1)
            {
                answer.push_back(cnt);
                cnt = 0;
            }
            day++;
        }
    }
    answer.push_back(cnt);

    return answer;
}