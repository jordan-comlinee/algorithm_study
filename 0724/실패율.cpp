#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Info
{
    int stageNumber;
    float probability;
    
    bool operator<(const Info& other) const
    {
        if(probability != other.probability)
        {
            return probability > other.probability;
        }
        return stageNumber < other.stageNumber;
    }
}info;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int totalPlayerNum = stages.size();
    
    vector<int> xStageFailPalyerNum(N + 2, 0);
    for(const int& stage : stages)
    {
        ++xStageFailPalyerNum[stage];
    }
    
    vector<info> failInfoList;
    
    int remainPlayer = totalPlayerNum;
    for(int stage = 1; stage <= N; ++stage)
    {
        int failPlayer = xStageFailPalyerNum[stage];

        float probability;
        if(remainPlayer > 0)
        {
            probability = static_cast<float>(failPlayer) / static_cast<float>(remainPlayer);
        }

        failInfoList.push_back({ stage, probability });

        remainPlayer -= failPlayer;
    }
    
    sort(failInfoList.begin(), failInfoList.end());

    for(const auto& info : failInfoList)
    {
        answer.emplace_back(info.stageNumber);
    }
    return answer;
}