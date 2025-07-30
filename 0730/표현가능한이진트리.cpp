#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> toBinary(long long number)
{
    long long n = number;
    vector<int> binary;
    while (n > 0)
    {
        binary.push_back(n % 2);
        n /= 2;
    }
    return binary;
}

int getFullTree(int s)
{
    int h = 1;
    while (pow(2, h) - 1 < s) h++;
    return pow(2, h) - 1;
}

int isBinaryTree(vector<int> binary)
{
    getFullTree(binary.size());
    return 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto number : numbers)
    {
        cout << number << endl;
        vector<int> binary;
        binary = toBinary(number);
        answer.push_back(isBinaryTree(binary));
    }
    return answer;
}