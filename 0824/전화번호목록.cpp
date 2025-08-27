#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {

    unordered_set<string> s(phone_book.begin(), phone_book.end());

    for (string num : phone_book)
    {
        string prefix = "";

        for (int i = 0; i < num.size() - 1; ++i)
        {
            prefix += num[i];

            if (s.find(prefix) != s.end())
            {
                return false;
            }
        }
    }
    return true;
}
