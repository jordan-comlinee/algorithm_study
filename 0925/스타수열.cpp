#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printtest(vector<int> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool gyoZipHap(vector<int> a, vector<int> b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            if (a[i] == b[j]) return true;
        }
    }
    return false;
}

bool checkStarVect(vector<int> v)
{
    vector<int> temp;

    for (int i = 0; i < v.size() - 1; i += 2)
    {
        if (v[i] == v[i + 1])
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> a)
{
    vector<int> SubVect;

    int answer = 0;
    int start = a.size() % 2 == 0 ? a.size() : a.size() - 1;

    for (int numOfComponent = start; numOfComponent >= 2; numOfComponent -= 2)
    {
        for (int i = 0; i <= a.size() - numOfComponent; ++i)
        {
            SubVect.resize(0);

            for (int j = i; j < i + numOfComponent; ++j)
            {
                SubVect.push_back(a[j]);
            }

            // 여기에 스타수열인지 판별

            printtest(SubVect);
            if (checkStarVect(SubVect))
            {

                return SubVect.size();
            }

            // --------------------
        }
    }
    return answer;
}