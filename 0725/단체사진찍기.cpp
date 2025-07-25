#include <string>
#include <vector>
#include <cmath>
using namespace std;
// ������ ���� ���� ������ ���� ������ ����
// 1. ������ ���� ����� ���� Ȱ���ؼ� ��� ��찡 �ִ��� Ȯ��
// 2. ������ �ִ� ����� �δ� ����� ���� ���Ѵ�.  -> �̰� ��� ����?
// 3. answer = 1*2

// 1. 8!�� ����� ���� ���� ��� 40320������ ������ ���Ѵ�.
// 2. ��͸� ���� ����� ���� ���� ���, data�� ������ Ȯ���Ѵ�.
// -> �ð� �ʰ��� ���ɼ��� �־��

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