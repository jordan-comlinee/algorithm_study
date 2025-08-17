#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

void makeLib(unordered_map<string, int>& lib)
{
    for (int i = 0; i < 26; ++i)
    {
        char ch = 'A' + i;
        string key(1, ch);
        lib[key] = i + 1;
    }
}

string find(const unordered_map<string, int>& lib, const string& msg, const int& idx, int& c)
{
    for (int i = c; i > 0; --i)
    {
        string k = msg.substr(idx, i);
        if (lib.find(k) != lib.end()) return k;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> lib;
    int idx = 0;
    int c = 1;
    int val = 27;
    makeLib(lib);

    while (idx < msg.size())
    {
        // �������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� w�� ã�´�.
        string w = find(lib, msg, idx, c);
        // w�� �ش��ϴ� ������ ���� ��ȣ�� ����ϰ�, �Է¿��� w�� �����Ѵ�.
        answer.push_back(lib[w]);
        idx += w.size();
        // �Է¿��� ó������ ���� ���� ���ڰ� �����ִٸ�(c), w+c�� �ش��ϴ� �ܾ ������ ����Ѵ�.
        if (idx < msg.size())
        {
            if (lib.find(w + msg[idx]) == lib.end())
            {
                lib[w + msg[idx]] = val++;
                int newKeySize = (w + msg[idx]).size();
                c = max(c, newKeySize);
            }

        }
    }
    return answer;
}