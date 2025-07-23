#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int BREAD = 1;
const int VEGET = 2;
const int PATTY = 3;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> st;
    vector<int> hamburger;
    const vector<int> example = { 1, 2, 3, 1 };
    for (auto in : ingredient)
    {
        st.push_back(in);
        int s = st.size() - 1;
        if (s >= 3 && st[s] == 1 && st[s - 1] == 3 && st[s - 2] == 2 && st[s - 3] == 1)
        {
            answer++;
            for (int i = 0; i < 4; ++i) st.pop_back();
        }
    }
    return answer;
}