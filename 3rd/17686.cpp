#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> files)
{
    vector<tuple<string, int, string, int>> parsed;
    vector<string> answer;
    for (int i = 0; i < files.size(); ++i)
    {
        string file = files[i];
        int len = file.size();
        int idx = 0;

        string head;
        while (idx < len && !isdigit(file[idx])) {
            head += file[idx++];
        }

        string numberStr;
        while (idx < len && isdigit(file[idx]) && numberStr.size() < 5) {
            numberStr += file[idx++];
        }
        //cout << head << " " << numberStr << endl;

        string lowerHead = head;
        for (int i = 0; i < lowerHead.size(); ++i)
        {
            lowerHead[i] = tolower(lowerHead[i]);
        }
        int number = stoi(numberStr);

        parsed.emplace_back(lowerHead, number, file, i);
    }

    sort(parsed.begin(), parsed.end(), [](const auto& a, const auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        return get<3>(a) < get<3>(b);
        });

    for (const auto& p : parsed) {
        answer.push_back(get<2>(p));
    }
    return answer;
}