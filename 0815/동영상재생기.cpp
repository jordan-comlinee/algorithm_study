#include <string>
#include <vector>
#include <iostream>
using namespace std;

void prev(int& time, const int& start, const int& end)
{
    time = time - 10 < 0 ? 0 : time - 10;
    if (start <= time && time <= end) time = end;
    return;
}

void next(int& time, const int& maxTime, const int& start, const int& end)
{
    time = time + 10 > maxTime ? maxTime : time + 10;
    if (start <= time && time <= end) time = end;
    return;
}

int stot(string& video)
{
    int minute = stoi(video.substr(0, 2));
    int sec = stoi(video.substr(3, 2));
    return minute * 60 + sec;
}

string ttos(const int time)
{
    string video = "00:00";
    string minute = to_string(time / 60);
    string second = to_string(time % 60);
    for (int i = minute.size() - 1; i >= 0; --i)
    {
        video[1 - (minute.size() - i - 1)] = minute[i];
    }
    for (int i = second.size() - 1; i >= 0; --i)
    {
        video[4 - (second.size() - i - 1)] = second[i];
    }
    return video;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int maxLen = stot(video_len);
    int time = stot(pos);
    int start = stot(op_start);
    int end = stot(op_end);
    if (start <= time && time <= end) time = end;
    for (auto command : commands)
    {
        if (command == "next")
        {
            next(time, maxLen, start, end);
        }
        else
        {
            prev(time, start, end);
        }
    }
    return ttos(time);
}