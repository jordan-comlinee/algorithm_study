#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(const char& c : s)
    {
        char changeC = c;
        int curIdx = 0;
        while(curIdx < index)
        {
            changeC++;
            if(changeC > 'z')
            {
                changeC = 'a';
            }

            bool isSkip = false;
            for(const char& skipC : skip)
            {
                if(changeC == skipC)
                {
                    isSkip = true;
                    break;
                }
            }

            if(isSkip)
            {
                continue;
            }
            
            curIdx++;
        }
        answer += changeC;
    }
    
    return answer;
}