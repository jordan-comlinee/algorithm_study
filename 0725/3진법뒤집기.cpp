#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 1;
    deque<int> q;
    while (n > 0)
    {
        q.push_front(n % 3);
        n /= 3;
    }
    while (!q.empty())
    {
        answer += q.front() * cnt;
        q.pop_front();
        cnt *= 3;
    }
    return answer;
}