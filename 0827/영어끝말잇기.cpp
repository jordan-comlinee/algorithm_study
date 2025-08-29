#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    const int wordSize = words.size();
    unordered_map<string, bool> dict;
        
    for(int idx = 0; idx < wordSize; ++idx)
    {
        const string& curWord = words[idx];

        if(idx > 0 && words[idx - 1].back() != curWord.front())
        {
            return { (idx % n) + 1, (idx / n) + 1 };
        }
        
        if(!dict[words[idx]])
        {
            dict[words[idx]] = true;
        }
        else
        {
            // answer.push_back({ (idx % n) + 1, (idx / n) + 1});
            return { (idx % n) + 1, (idx / n) + 1};            
        }
        
    }
    
    // answer.push_back({ 0, 0 });
    
    return { 0, 0 };
}