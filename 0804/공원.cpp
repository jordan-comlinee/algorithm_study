#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check(int i, int j, vector<vector<string>>& park) {
    int maxSize = 1;
    int r = park.size();
    int c = park[0].size();

    while (true) {
        if (i + maxSize >= r || j + maxSize >= c) break;
        for (int k = 0; k <= maxSize; ++k) {
            if (park[i + k][j + maxSize] != "-1") return maxSize;
            if (park[i + maxSize][j + k] != "-1") return maxSize;
        }
        maxSize++;
    }
    return maxSize;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int r = park.size();
    int c = park[0].size();
    sort(mats.begin(), mats.end(), greater<int>());
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (park[i][j] == "-1")
            {
                answer = max(answer, check(i, j, park));
            }
        }
    }
    for (auto m : mats)
    {
        if (m <= answer) return m;
    }

    return -1;
}