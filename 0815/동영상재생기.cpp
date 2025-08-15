#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int now_h = stoi(pos.substr(0,2));
    int now_m = stoi(pos.substr(3,2));
    now_m += (now_h * 60);
    int op_s_h = stoi(op_start.substr(0,2));
    int op_s_m = stoi(op_start.substr(3,2));
    op_s_m += (op_s_h * 60);
    
    int op_e_h = stoi(op_end.substr(0,2));
    int op_e_m = stoi(op_end.substr(3,2));
    op_e_m += (op_e_h * 60);
    
    int end_h = stoi(video_len.substr(0,2));
    int end_m = stoi(video_len.substr(3,2));
    end_m += (end_h * 60);
    if(op_s_m<=now_m && now_m <= op_e_m)
            now_m = op_e_m;
    for(const auto& t : commands)
    {
        if(t == "next")
            now_m+=10;
        else
            now_m-=10;
        if(now_m<0)
            now_m = 0;
        if(now_m>end_m)
            now_m = end_m;
        if(op_s_m<=now_m && now_m <= op_e_m)
            now_m = op_e_m;
    }
    if(now_m / 60 < 10)
        answer+="0";
    answer+= to_string(now_m / 60);
    answer+= ":";
    if(now_m % 60 < 10)
        answer+="0";
    answer+= to_string(now_m % 60);
    return answer;
}
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
동영상재생기.cpp [unix] (08:59 01/01/1970)                             0,0-1 All
"동영상재생기.cpp" [New]

