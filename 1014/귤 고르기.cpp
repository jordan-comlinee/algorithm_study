#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {

    sort(tangerine.begin(), tangerine.end());

    vector<int> counts;
    int current = tangerine[0];
    int freq = 1;

    for (size_t i = 1; i < tangerine.size(); ++i)
    {
        if (tangerine[i] == current)
        {
            freq++;
        }
        else
        {
            counts.push_back(freq);
            current = tangerine[i];
            freq = 1;
        }
    }
    counts.push_back(freq);

    sort(counts.begin(), counts.end(), greater<int>());

    int used_types = 0;
    int taken = 0;

    for (size_t i = 0; i < counts.size(); ++i)
    {
        taken += counts[i];
        used_types++;
        if (taken >= k) break;
    }

    return used_types;
}