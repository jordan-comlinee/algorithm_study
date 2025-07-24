#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, map<string, bool>>reporterReportedMap;
    map<string, int> reportedUser;  // 신고된 유저, 횟수 순
    
    for(int idx = 0; idx < id_list.size(); ++idx)
    {
        // id_list[idx] = 
    }
    
    for (const string& s : report)
    {
        istringstream iss(s);
        string reporter, reported;
        iss >> reporter >> reported;

        if (!reporterReportedMap[reporter][reported])
        {
            reporterReportedMap[reporter][reported] = true;
            ++reportedUser[reported];
        }
    }
    
    for(const auto& rrmap : reporterReportedMap)
    {
        const string& reporter = rrmap.first;
        
        for (const auto& reportedPerson : rrmap.second)
        {
            const string& reported = reportedPerson.first;

            if(reportedPerson.second && reportedUser[reported] >= k)
            {
                auto findPointer = find(id_list.begin(), id_list.end(), reporter);
                int idx = findPointer - id_list.begin();
                ++answer[idx];
            }
        }
    }
    
    return answer;
}