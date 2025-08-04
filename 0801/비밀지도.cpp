#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n, ' '));
    for (int i = 0; i < arr1.size(); ++i)
    {
        int idx = n - 1;
        while (arr1[i] > 0 || arr2[i] > 0)
        {
            answer[i][idx] = (arr1[i] % 2 | arr2[i] % 2) == 1 ? '#' : ' ';
            arr1[i] /= 2;
            arr2[i] /= 2;
            idx--;
        }
    }
    return answer;
}