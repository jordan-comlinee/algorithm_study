#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0;
    int grade = 7;
    set<int> lotto_set;
    for (auto lotto : lottos)
    {
        lotto_set.insert(lotto);
        if (lotto == 0) zero++;
    }
    for (auto win : win_nums)
    {
        if (lotto_set.find(win) != lotto_set.end()) grade--;
    }
    answer.push_back((grade - zero) > 6 ? 6 : (grade - zero));
    answer.push_back(grade > 6 ? 6 : grade);
    return answer;
}