#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size();

    vector<int> prev;
    prev.resize(4);
    for (int j = 0; j < 4; ++j) 
    {
        prev[j] = land[0][j];
    }

    for (int i = 1; i < n; ++i) 
    {
        vector<int> cur;
        cur.resize(4);
        for (int j = 0; j < 4; ++j) 
        {
            int best = 0;
            for (int k = 0; k < 4; ++k) 
            {
                if (k != j) 
                {
                    if (prev[k] > best) 
                    {
                        best = prev[k];
                    }
                }
            }
            cur[j] = land[i][j] + best;
        }
        prev = cur;
    }

    int answer = prev[0];
    for (int j = 1; j < 4; ++j) 
    {
        if (prev[j] > answer) 
        {
            answer = prev[j];
        }
    }
    return answer;
}