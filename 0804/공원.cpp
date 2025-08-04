#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

bool check_valid(int ipos, int jpos, int size, vector<vector<string>> park)
{
    for (int i = ipos; i < ipos + size; ++i)
    {
        for (int j = jpos; j < jpos + size; ++j)
        {
            if (i < 0 || j < 0 || i >= park.size() || j >= park[0].size())
            {
                return false;
            }
            else if (park[i][j] != "-1")
            {
                return false;
            }
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {

    vector<int> mat = mats;
    sort(mat.begin(), mat.end(), compare);

    for (int m = 0; m < mat.size(); ++m)
    {
        for (int i = 0; i < park.size(); ++i)
        {
            for (int j = 0; j < park[0].size(); ++j)
            {
                if (check_valid(i, j, mat[m], park)) return mat[m];
            }
        }
    }

    return -1;
}