#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    sort(mats.rbegin(), mats.rend());
    
    int parksSize = park.size();
    int parkSize = park[0].size();
    
    for(const int& mat : mats)
    {        
        for(int i = 0; i <= parksSize - mat; ++i)
        {
            for(int j = 0; j <= parkSize - mat; ++j)
            {
                bool can = true;
                
                for(int ii = 0; ii < mat && can; ++ii)
                {
                    for(int jj = 0; jj < mat; ++jj)
                    {
                        if(park[i + ii][j + jj] != "-1")
                        {
                            can = false;
                            break;
                        }
                    }
                }
                if(can)
                {
                    return mat;
                }
            }
        }
    }
    
    return -1;
}   