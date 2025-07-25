#include <string>
#include <vector>
#include <set>

using namespace std;

set<pair<int, int>> rotateKey(const set<pair<int, int>>& rotateKey)
{
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    const int m =  key.size();
    const int n = lock.size();
    
    set<pair<int, int>> lockPattern;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (lock[y][x] == 0)
            {
                lockPattern.insert({y, x});
            }
        }
    }
    
    set<pair<int, int>> keyPattern;
    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            if (key[y][x] == 1)
            {
                keyPattern.insert({y, x});
            }
        }
    }
        
    if(lockPattern.empty())
    {
        return true;
    }
    
    vector<set<pair<int, int>>> rotateKey = {keyPattern};
    for(int i = 0; i < 3; ++i)
    {
        rotateKey.emplace_back()
    }
    
    
    
    return answer;
}