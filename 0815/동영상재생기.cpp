#include <string>
#include <vector>

using namespace std;

int toSec(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

string secToTime(int time)
{
    int timemin = time / 60;
    int timesec = time % 60;

    string mm = to_string(timemin);
    string ss = to_string(timesec);

    if (timemin < 10) mm = "0" + mm;
    if (timesec < 10) ss = "0" + ss;

    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    int time = toSec(pos);

    if (time >= toSec(op_start) && time <= toSec(op_end))
    {
        time = toSec(op_end);
    }

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "next")
        {
            if (toSec(video_len) - time > 10)
                time += 10;
            else
                time = toSec(video_len);
        }
        else if (commands[i] == "prev")
        {
            if (time > 10)
                time -= 10;
            else
                time = 0;
        }

        if (time >= toSec(op_start) && time <= toSec(op_end))
        {
            time = toSec(op_end);
        }
    }

    return secToTime(time);
}
