#include <string>
#include <vector>
#include <cmath>
using namespace std;
// 순열과 조합 관련 문제가 있을 것으로 예상
// 1. 조건이 없는 멤버는 순열 활용해서 몇가지 경우가 있는지 확인
// 2. 조건이 있는 멤버를 두는 경우의 수를 구한다.  -> 이걸 어떻게 구함?
// 3. answer = 1*2

// 1. 8!의 경우의 수를 가진 모든 40320가지의 순열을 구한다.
// 2. 재귀를 통한 경우의 수가 나온 경우, data의 조건을 확인한다.
// -> 시간 초과의 가능성이 있어보임

const vector<string> kakao = { "A", "C", "F", "J", "M", "N", "R", "T" };

bool check(vector<string> members, vector<string>& data)
{
    for (auto d : data)
    {
        int posa, posb;
        char a = d[0];
        char b = d[2];
        char sign = d[3];
        int condition = d[4] - '0';
        for (int i = 0; i < 8; ++i)
        {
            if (members[i][0] == a) posa = i;
            if (members[i][0] == b) posb = i;
        }
        switch (sign)
        {
        case '=':
            if (abs(posa - posb) - 1 != condition) return false;
            break;
        case '<':
            if (abs(posa - posb) - 1 >= condition) return false;
            break;
        case '>':
            if (abs(posa - posb) - 1 <= condition) return false;
            break;
        default:
            break;
        }
    }
    return true;
}

void dfs(vector<string> members, vector<bool> visited, int& answer, vector<string>& data)
{
    if (members.size() == 8 && check(members, data))
    {
        answer++;
        return;
    }
    for (int i = 0; i < visited.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            members.push_back(kakao[i]);
            dfs(members, visited, answer, data);
            visited[i] = false;
            members.pop_back();
        }

    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<bool> visited(8, false);
    dfs(vector<string>(), visited, answer, data);
    return answer;
}