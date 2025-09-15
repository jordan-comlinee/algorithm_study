#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

static inline string fillQ(const string& q, char fill)
{
    string s = q;
    for (char &c : s) if (c == '?') c = fill;
    return s;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(), 0);

    // 길이별 정렬된 단어 리스트, 길이별 정렬된 "뒤집은 단어" 리스트
    unordered_map<int, vector<string>> frt; // 접두 검색용
    unordered_map<int, vector<string>> lst; // 접미 검색용(뒤집어서 접두처럼)
    unordered_map<int, int> cnt;            // 길이별 전체 개수

    // 전처리: 길이별로 분류 후 정렬 (lst는 단어를 뒤집어 저장)
    for (const auto& t : words) {
        int sz = (int)t.size();
        frt[sz].push_back(t);

        string u = t;
        reverse(u.begin(), u.end());
        lst[sz].push_back(u);

        cnt[sz]++;
    }
    for (auto &kv : frt) sort(kv.second.begin(), kv.second.end());
    for (auto &kv : lst) sort(kv.second.begin(), kv.second.end());

    // 쿼리 처리: 이분 탐색으로 개수 계산
    int idx = 0;
    for (const auto& t : queries) {
        int sz = (int)t.size();

        // 해당 길이의 단어가 아예 없으면 0
        if (cnt.find(sz) == cnt.end()) { idx++; continue; }

        // 전부 '?' 인 경우: 길이만 맞으면 모두 매칭
        if (t[0] == '?' && t[sz - 1] == '?') {
            answer[idx++] = cnt[sz];
            continue;
        }

        if (t[0] == '?') {
            // 접미 고정 → 쿼리를 뒤집어서 접두 검색으로 변환, lst[sz] 사용
            string rq = t;
            reverse(rq.begin(), rq.end());
            string lo = fillQ(rq, 'a');
            string hi = fillQ(rq, 'z');
            auto &vec = lst[sz];
            auto it1 = lower_bound(vec.begin(), vec.end(), lo);
            auto it2 = upper_bound(vec.begin(), vec.end(), hi);
            answer[idx] = (int)(it2 - it1);
        } else {
            // 접두 고정 → frt[sz] 사용
            string lo = fillQ(t, 'a');
            string hi = fillQ(t, 'z');
            auto &vec = frt[sz];
            auto it1 = lower_bound(vec.begin(), vec.end(), lo);
            auto it2 = upper_bound(vec.begin(), vec.end(), hi);
            answer[idx] = (int)(it2 - it1);
        }
        idx++;
    }

    return answer;
}

