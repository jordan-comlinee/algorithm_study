#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> getCombination(string str, int cnt) {
    vector<string> result;
    int n = str.size();
    vector<int> select(n, 0);
    fill(select.end() - cnt, select.end(), 1);
    do
    {
        string tmp;
        for (int i = 0; i < n; ++i)
        {
            if (select[i]) tmp.push_back(str[i]);
        }
        result.push_back(tmp);
    } while (next_permutation(select.begin(), select.end()));
    return result;
}

vector<string> findCommonCourse(vector<string> everyCourse) {
    vector<string> result;
    int maxFreq = 0;
    unordered_map<string, int> frequency;
    for (auto course : everyCourse) {
        frequency[course] += 1;
        maxFreq = max(maxFreq, frequency[course]);
    }
    if (maxFreq >= 2) {
        for (auto [name, freq] : frequency) {
            if (freq == maxFreq) {
                result.push_back(name);
            }
        }
    }
    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto& order : orders)
    {
        sort(order.begin(), order.end());
    }
    // cnt���� ��Ҹ� ���� �� �ִ� ��� �ڽ� ���� ���ϱ�
    for (auto cnt : course)
    {
        vector<string> everyCourse;
        vector<string> commonCourse;
        // orders ������ ��� ã��
        for (auto order : orders)
        {
            if (order.size() < cnt) continue;
            vector<string> combinations = getCombination(order, cnt);
            everyCourse.insert(everyCourse.end(), combinations.begin(), combinations.end());
        }
        // ���� �߿��� ���� ���� ���� �͵� ã�Ƽ� answer�� �ֱ�
        commonCourse = findCommonCourse(everyCourse);
        answer.insert(answer.end(), commonCourse.begin(), commonCourse.end());
    }
    sort(answer.begin(), answer.end());
    return answer;
}