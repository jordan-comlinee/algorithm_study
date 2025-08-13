#include <string>
#include <vector>

using namespace std;

int hTm(const string& time)
{
    const int hour = stoi(time.substr(0, 2));
    const int min = stoi(time.substr(3, 2));
    return hour * 60 + min;
}

string mTh(const int& time)
{
    const int hour = time / 60;
    const int min = time % 60;
    
    string sHour = "";
    string sMin = "";
    
    if(hour < 10)
    {
        sHour += "0";
        sHour += to_string(hour);
    }
    else
    {
        sHour += to_string(hour);
    }
    
    if(min < 10)
    {
        sMin += "0";
        sMin += to_string(min);
    }
    else
    {
        sMin += to_string(min);
    }
    
    
    return sHour + ":" + sMin;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    #if 0
    
    명령어
        - prev -> 10초 전으로 이동(현재 시간 < 10 => 00:00으로 이동)
        - next -> 10초 후로 이동 (남은 시간 < 10 => 마지막 위치로 이동)
        - 오프닝 건너뛰기(op_start <= 현재 재생 위치 <= op_end => op_end로 이동)        
    #endif
    
    int curPos = hTm(pos);
    const int endPos = hTm(video_len);
    
    for(const string& command : commands)
    {
        if((curPos >= hTm(op_start)) && (curPos <= hTm(op_end)))
        {
            curPos = hTm(op_end);
        }
        
        if(command == "prev")
        {
            if(curPos < 10)
            {
                curPos = 0;
            }
            else
            {
                curPos -= 10;
            }
        }
        else if(command == "next")
        {
            if(endPos - curPos < 10)
            {
                curPos = endPos;
            }
            else
            {
                curPos += 10;
            }
        }
    }
    
    if((curPos >= hTm(op_start)) && (curPos <= hTm(op_end)))
    {
        curPos = hTm(op_end);
    }
    
    return mTh(curPos);
}