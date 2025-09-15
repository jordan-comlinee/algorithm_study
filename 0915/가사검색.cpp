#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int find(string& query, vector<string>& dict)
{
	string start = query;
	string end = query;
	for (char& c : start)
		if (c == '?') c = 'a';
	for (char& c : end)
		if (c == '?') c = 'z';
	int l = lower_bound(dict.begin(), dict.end(), start);
	int r = upper_bound(dict.begin(), dict.end(), end);
	return r - l;
}


vector<int> solution(vector<string> words, vector<string> queries)
{
	vector<int> answer;
	unordered_map<int, vector<string>> dict;
	unordered_map<int, vector<string>> r_dict;

	for (auto word : words)
	{
		dict[word.size()].push_back(word);
		reverse(word.begin(), word.end());
		r_dict[word.size()].push_back(word);
	}
	for (auto& [k, d] : dict)
	{
		sort(d.begin(), d.end());
	}
	for (auto& [k, d] : r_dict)
	{
		sort(d.begin(), d.end());
	}
	for (auto query : queries)
	{
		if (query[0] == '?')
		{
			reverse(query.begin(), query.end());
			answer.push_back(find(query, r_dict[query.size()]));
		}
		else
		{
			answer.push_back(find(query, dict[query.size()]));
		}
	}
	return answer;

}