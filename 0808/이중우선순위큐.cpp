#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    multiset<int> set;
    int size = 0;
    for (auto op : operations)
    {
        int target = stoi(op.substr(1));
        switch (op[0])
        {
        case 'I':
            pq1.push(target);
            pq2.push(target);
            set.insert(target);
            size++;
            break;
        case 'D':
            if (size > 0)
            {
                if (target == 1)
                {
                    set.erase(pq1.top());
                    pq1.pop();
                }
                else
                {
                    set.erase(pq2.top());
                    pq2.pop();
                }
                size--;
            }
            break;
        default:
            break;
        }
        if (size == 0)
        {
            pq1 = priority_queue<int>();
            pq2 = priority_queue<int, vector<int>, greater<int>>();
        }
    }
    if (size == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (size == 1)
    {
        int i = set.find(pq1.top()) != set.end() ? pq1.top() : pq2.top();
        answer.push_back(i);
        answer.push_back(i);

    }
    else
    {
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }
    return answer;
}