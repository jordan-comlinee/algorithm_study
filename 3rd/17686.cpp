#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct fileInfo
{
    string init;
    string head;
    int number;
    int idx;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    int filesSize = files.size();
    vector<fileInfo> fInfo;
    
    for (int idx = 0; idx < filesSize; ++idx)
    {
        const string& file = files[idx];
        // head/number/tail
        int i = 0;
        int len = file.size();
        string head = "";
        string number = "";

        while (i < len && !(file[i] >= '0' && file[i] <= '9'))
        {
            head += file[i++];
        }

        while (i < len && (file[i] >= '0' && file[i] <= '9') && number.size() < 5)
        {
            number += file[i++];
        }

        string tolowerHead = head;
        for (int j = 0; j < tolowerHead.size(); ++j)
        {
            if (tolowerHead[j] >= 'A' && tolowerHead[j] <= 'Z')
            {
                tolowerHead[j] = tolowerHead[j] - 'A' + 'a';
            }
        }
        fInfo.push_back({file, tolowerHead, stoi(number), idx});
    }
            
    sort(fInfo.begin(), fInfo.end(), [](const fileInfo& a, const fileInfo& b){
        if(a.head != b.head)
        {
            return a.head < b.head;
        }
        if(a.number != b.number)
        {
            return a.number < b.number;
        }
        return a.idx < b.idx;
    });
    
    for (const auto& info : fInfo)
    {
        answer.push_back(info.init);
    }
    
    return answer;
}