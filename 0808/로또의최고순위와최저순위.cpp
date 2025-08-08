#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {

    vector<int> answer;

    int count = 0;
    int count_zero = 0;

    for (int l = 0; l < lottos.size(); ++l)
    {
        if (lottos[l] == 0)
        {
            count_zero++;
        }
        else if (find(win_nums.begin(), win_nums.end(), lottos[l]) != win_nums.end())
        {
            count++;
        }
    }
    int best = count_zero + count >= 2 ? 7 - (count_zero + count) : 6;
    int worst = count >= 2 ? 7 - count : 6;

    answer.push_back(best);
    answer.push_back(worst);

    return answer;
}