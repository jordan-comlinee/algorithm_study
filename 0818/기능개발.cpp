#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> make(vector<int> progresses, vector<int> speeds)
{
    vector<int> progress = progresses;
    for (int i = 0; i < progress.size(); ++i)
    {
        progress[i] += speeds[i];
    }
    return progress;
}

int checkAll(vector<int> progresses)
{
    int answer = 0;

    for (int i = 0; i < progresses.size(); ++i)
    {
        if (progresses[i] >= 100)
        {
            answer++;
        }
        else
        {
            break;
        }
    }
    return answer;
}

vector<int> deleteAll(vector<int> progresses)
{
    vector<int> progress = progresses;

    while (!progress.empty())
    {
        if (progress[0] >= 100)
        {
            progress.erase(progress.begin());
        }
        else
        {
            break;
        }
    }
    return progress;
}

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> progress = progresses;

    while (1)
    {
        progress = make(progress, speeds);
        int complete = checkAll(progress);

        if (complete >= 1)
        {
            for (int i = 0; i < complete; ++i)
            {
                speeds.erase(speeds.begin());
            }
            progress = deleteAll(progress);
            answer.push_back(complete);
        }

        if (progress.empty())
        {
            break;
        }
    }

    return answer;
}