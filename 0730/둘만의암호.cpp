#include <string>
#include <vector>

using namespace std;

char Next_Char(char c)
{
    if (c == 'z')
    {
        return'a';
    }
    else
    {
        return c + 1;
    }
}

string solution(string s, string skip, int index) {

    string answer = "";
    for (int i = 0; i < s.size(); ++i)
    {
        int check = 0;
        char temp;
        temp = s[i];

        while (1)
        {
            temp = Next_Char(temp);

            bool flag = false;
            for (int j = 0; j < skip.size(); ++j)
            {
                if (temp == skip[j])
                {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;

            check++;

            if (check == index)
            {
                answer += temp;
                break;
            }
        }
    }

    return answer;
}