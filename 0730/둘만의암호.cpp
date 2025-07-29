#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(string s, string skip, int index) 
{
    unordered_map<char, bool> m;
    unordered_map<char, int> mm;
    for(const auto& t : skip)
    {
        m[t] = true;
    }
    vector<char> arr;
    int idx = 0;
    for(int i = 0; i<26; i++)
    {
        if(m['a'+i] == true)
            continue;
        arr.push_back('a'+i);
        mm['a'+i] = idx++;
    }
    string ans = "";
    for(auto& t : s)
    {
        ans+=arr[(mm[t]+index)%idx];
    }
    return ans;
}
