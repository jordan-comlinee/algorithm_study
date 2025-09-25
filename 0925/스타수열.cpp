#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    unordered_map<int, int> freq;
    for (int x : a) freq[x]++;

    int answer = 0;
    for (auto [num, f] : freq) {
        if (f * 2 <= answer) continue;

        int len = 0;
        for (int i = 0; i < n - 1; i++) {
            if ((a[i] == num || a[i + 1] == num) && a[i] != a[i + 1]) {
                len += 2;
                i++;
            }
        }
        answer = max(answer, len);
    }
    return answer;
}
