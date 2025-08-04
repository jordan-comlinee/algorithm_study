#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define Pillar 0
#define Puddle 1

using namespace std;

vector<int> temp;

bool compare(vector<int> a, vector<int> b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else if (a[1] != b[1])
        return a[1] < b[1];
    else
        return a[2] < b[2];
}

bool pulldata(vector<int> a, vector<int> b)
{
    if (a == temp && b != temp) return false;
    if (b == temp && a != temp) return true;
    return compare(a, b);
}

bool check_valid(vector<vector<int>> map)
{
    for (int i = 0; i < map.size(); ++i)
    {
        int x = map[i][0];
        int y = map[i][1];
        int a = map[i][2];

        if (a == Pillar) {
            if (y == 0 ||
                find(map.begin(), map.end(), vector<int>{x, y - 1, Pillar}) != map.end() ||
                find(map.begin(), map.end(), vector<int>{x - 1, y, Puddle}) != map.end() ||
                find(map.begin(), map.end(), vector<int>{x, y, Puddle}) != map.end()) {
                continue;
            }
            return false;
        }
        else if (a == Puddle) {
            if ((find(map.begin(), map.end(), vector<int>{x, y - 1, Pillar}) != map.end() &&
                find(map.begin(), map.end(), vector<int>{x + 1, y - 1, Pillar}) != map.end()) ||
                (find(map.begin(), map.end(), vector<int>{x - 1, y, Puddle}) != map.end() &&
                    find(map.begin(), map.end(), vector<int>{x + 1, y, Puddle}) != map.end()) ||
                (find(map.begin(), map.end(), vector<int>{x, y - 1, Pillar}) != map.end()) ||
                (find(map.begin(), map.end(), vector<int>{x + 1, y - 1, Pillar}) != map.end())) {
                continue;
            }
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> map;
    temp.resize(3);

    for (int i = 0; i < build_frame.size(); ++i)
    {
        temp[0] = build_frame[i][0];
        temp[1] = build_frame[i][1];
        temp[2] = build_frame[i][2];

        if (build_frame[i][3] == 1)
        {
            map.push_back(temp);

            if (!check_valid(map)) map.pop_back();
        }
        else if (build_frame[i][3] == 0)
        {
            sort(map.begin(), map.end(), pulldata);

            if (!map.empty() && map.back() == temp) {

                map.pop_back();
                if (!check_valid(map)) map.push_back(temp);
            }
        }
    }

    sort(map.begin(), map.end(), compare);
    return map;
}
