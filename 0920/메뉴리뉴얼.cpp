#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string LCS_Find(string S1, string S2) {

    vector<vector<int>> LCS_LEN;

    LCS_LEN.resize(S1.size() + 1);
    for (int i = 0; i < S1.size() + 1; ++i) {
        LCS_LEN[i].resize(S2.size() + 1);
    }

    for (int i = 1; i <= S1.size(); ++i) {

        for (int j = 1; j <= S2.size(); ++j) {

            if (S1[i - 1] == S2[j - 1]) {
                LCS_LEN[i][j] = LCS_LEN[i - 1][j - 1] + 1;
            }
            else {
                LCS_LEN[i][j] = max(LCS_LEN[i][j - 1], LCS_LEN[i - 1][j]);
            }
        }
    }
    string LCS_STRING = "";

    int i = S1.size();
    int j = S2.size();

    while (i > 0 && j > 0) {

        if (S1[i - 1] == S2[j - 1]) {
            LCS_STRING = S1[i - 1] + LCS_STRING;
            i--;
            j--;
        }
        else if (LCS_LEN[i - 1][j] > LCS_LEN[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    return LCS_STRING;
}

vector<string> solution(vector<string> orders, vector<int> course) {

    vector<string> answer;
    vector<string> candidate;

    for (int i = 0; i < orders.size() - 1; ++i) {

        for (int j = i + 1; j < orders.size(); ++j) {

            sort(orders[i].begin(), orders[i].end());
            sort(orders[j].begin(), orders[j].end());

            if (count(course.begin(), course.end(), LCS_Find(orders[i], orders[j]).size()) != 0) {

                if (count(answer.begin(), answer.end(), LCS_Find(orders[i], orders[j])) == 0) {
                    answer.push_back(LCS_Find(orders[i], orders[j]));
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}