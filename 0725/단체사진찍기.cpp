#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define Person1 0
#define Person2 2
#define Restrict 3
#define Distance 4

using namespace std;

int find_idx(char c, vector<char> data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i] == c) return i;
    }
}

//permutation은 algorithm에 정의되어 있음!!!

int solution(int n, vector<string> data) {

    vector<char> people = { 'A','C','F','J','M','N','R','T' };
    int answer = 0;

    do {
        bool flag = true;

        for (int RNum = 0; RNum < data.size(); ++RNum)
        {
            char person1 = data[RNum][Person1];
            char person2 = data[RNum][Person2];
            char restriction = data[RNum][Restrict];
            int dist = data[RNum][Distance] - '0';

            int gap = abs(find_idx(person1, people) - find_idx(person2, people)) - 1;

            if (restriction == '=' && gap != dist)
            {
                flag = false;
                break;
            }
            if (restriction == '>' && gap <= dist)
            {
                flag = false;
                break;
            }
            if (restriction == '<' && gap >= dist)
            {
                flag = false;
                break;
            }
        }
        if (flag) answer++;

    } while (next_permutation(people.begin(), people.end()));

    return answer;
}
