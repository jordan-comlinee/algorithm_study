#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string to_Samjin(int n)
{
    int p = 0;
    int Num = n;
    string result = "";

    while (1)
    {
        if (pow(3, p) > n) break;
        p = p + 1;
    }
    int maxpow = p - 1;

    for (int p = maxpow; p >= 0; p--)
    {
        result += to_string(Num / (int)pow(3, p));
        Num = Num % (int)pow(3, p);
    }
    return result;
}

int to_demical(string n)
{
    int result = 0;
    string temp = "0";
    for (int i = 0; i < n.size(); ++i)
    {
        temp[0] = n[i]; // char을 string으로 바꾸어주기
        result += stoi(temp) * pow(3, n.size() - 1 - i);
    }
    return result;
}

int solution(int n) {

    string reNumber = to_Samjin(n);
    reverse(reNumber.begin(), reNumber.end());
    return to_demical(reNumber);
}