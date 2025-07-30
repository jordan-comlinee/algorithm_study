#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string to_binary(int num)
{
    string answer = "";
    while (num != 0)
    {
        answer += to_string(num % 2);
        num = num / 2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

bool check_valid(string bin, int start, int end)
{
    if (start > end) return true;

    int mid = (start + end) / 2;
    char root = bin[mid];

    int left_mid = (start + mid - 1) / 2;
    int right_mid = (mid + 1 + end) / 2;

    if (root == '0')
    {
        if ((mid > start && bin[(start + mid - 1) / 2] == '1') || (mid < end && bin[(mid + 1 + end) / 2] == '1'))
        {
            return false;
        }
    }
    return check_valid(bin, start, mid - 1) && check_valid(bin, mid + 1, end); //양옆 검사 고고
}

vector<int> solution(vector<long long> numbers) {

    vector<int> answer;
    for (int i = 0; i < numbers.size(); ++i)
    {
        string binary_num = "";
        binary_num = to_binary(numbers[i]);
        string full_binary_num = "";

        int h = 0;

        while (pow(2, h) - 1 < binary_num.size()) ++h;

        int fullLen = pow(2, h) - 1;

        for (int j = 0; j < fullLen - binary_num.size(); ++j)
        {
            full_binary_num += '0';
        }

        full_binary_num += binary_num;

        if (check_valid(full_binary_num, 0, full_binary_num.size() - 1))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}