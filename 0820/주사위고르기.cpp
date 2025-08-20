#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    vector<int> select = { 0,1,0,1 };

    do {

        for (int i = 0; i < select.size(); ++i)
        {
            cout << select[i] << " ";
        }

        cout << endl;

    } while (next_permutation(select.begin(), select.end()));

    return answer;
}