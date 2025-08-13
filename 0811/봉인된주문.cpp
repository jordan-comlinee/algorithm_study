#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
vector<char> alphabet(27);

string change(vector<int> nums)
{
    string res = "";
    for(int i = 0; i<nums.size(); i++)
    {
        res = alphabet[nums[i]] + res;
    }
    return res;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<int> ban_cnt(12, 0);
    vector<vector<string>> ban(12);
    
    // 자리수에 안되는 단어 개수 추가, 단어들 뭐있는지 추가
    for(const auto& t : bans)
    {
        ban_cnt[t.size()]++;
        ban[t.size()].push_back(t);
    }
    
    // 알파벳 배열 생성
    for(int i = 1; i<27; i++)
        alphabet[i] = 'a'+i-1;
    
    vector<int> nums;
    
    // 26진수 유사하게 변환
    while(n)
    {
        if(n%26)
        {
            nums.push_back(n%26);
            n/=26;
        }
        else
        {
            nums.push_back(26);
            n-=26;
            n/=26;
        }
    }
    int len = nums.size();
    int total = 0;
    for(int i = 1; i<len; i++)
    {
        total += ban_cnt[i];
    }
    nums[0]+=total;
    for(int i = 0; i<nums.size(); i++)
    {
        if(nums[i]<=26)
            break;
        while(!(nums[i]<=26))
        {
            nums[i]-=26;
            nums[i+1]++;
        }
    }

    total = 0;
    while(len != nums.size())
    {
        for(int i = len; i<nums.size(); i++)
        {
            total += ban_cnt[i];
        }
        len = nums.size();
        nums[0]+=total;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]<=26)
                break;
            while(!(nums[i]<=26))
            {
                nums[i]-=26;
                nums[i+1]++;
            }
        }
    }
    
    sort(ban[len].begin(), ban[len].end());
    string s = change(nums);
    for(int i = 0; i<ban[len].size(); i++)
    {
        if(ban[len][i].compare(s) <= 0)
        {
            nums[0]++;
            for(int j = 0; j<nums.size(); j++)
            {
                if(nums[j]<=26)
                    break;
                while(!(nums[j]<=26))
                {
                    nums[j]-=26;
                    nums[j+1]++;
                }
            }
            s = change(nums);
        }
        else break;
    }

    answer = change(nums);
    return answer;
}
