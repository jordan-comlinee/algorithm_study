#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    unordered_map<int, int> indeg, outdeg;
    unordered_map<int, bool> seen;

    for (const auto& e : edges) {
        int u = e[0], v = e[1];
        outdeg[u]++; 
        indeg[v]++;
        seen[u] = true;
        seen[v] = true;
    }

    int created = 0;
    for (const auto& [v, _] : seen) {
        if (indeg[v] == 0 && outdeg[v] >= 2) {
            created = v;
            break;
        }
    }

    int sticks = 0; 
    int eights = 0; 
    for (const auto& [v, _] : seen) {
        if (v == created) continue;
        if (outdeg[v] == 0) sticks++;
        else if (outdeg[v] == 2 && indeg[v] >= 2) eights++;
    }

    int donuts = outdeg[created] - sticks - eights;

    return {created, donuts, sticks, eights};
}

