// 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;
BEGIN: https://www.hrwhisper.me/leetcode-reconstruct-itinerary/
class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> result;
		if (tickets.empty()) return result;
		unordered_map<string, map<string, int>> graph;
		for (const auto& i : tickets) graph[i.first][i.second]++;
		result.push_back("JFK");
		this->backTrack(tickets.size(), result, graph);
		return result;
	}
private:
	bool backTrack(const size_t lengthOftickets, vector<string>& result, unordered_map<string, map<string, int>>& graph) {
		if (result.size() == (lengthOftickets + 1)) return true;
		for (auto& i : graph[result.back()]) {
			if (i.second == 0) continue;
			i.second--;
			result.push_back(i.first);
			if (this->backTrack(lengthOftickets, result, graph)) return true;
			i.second++;
			result.pop_back();			
		}
		return false;
	}
};
// BEGIN: https://discuss.leetcode.com/topic/36721/short-c-dfs-iterative-44ms-solution-with-explanation-no-recursive-calls-no-backtracking
// class Solution {
// public:
// 	vector<string> findItinerary(vector<pair<string, string>> tickets) {
// 		unordered_map<string, multiset<string>> graph;
// 		for (const auto &i : tickets) graph[i.first].insert(i.second);
// 		vector<string> result;
// 		stack<string> stk;
// 		stk.push("JFK");
// 		while (!stk.empty()) {
// 			string top = stk.top();
// 			if (graph[top].empty()) {
// 				result.push_back(top);
// 				stk.pop();
// 			}
// 			else {
// 				stk.push(*begin(graph[top]));
// 				graph[top].erase(begin(graph[top]));
// 			}
// 		}
// 		reverse(begin(result), end(result));
// 		return result;
// 	}
// };
// END: https://discuss.leetcode.com/topic/36721/short-c-dfs-iterative-44ms-solution-with-explanation-no-recursive-calls-no-backtracking
// END: https://www.hrwhisper.me/leetcode-reconstruct-itinerary/
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<string> findItinerary(vector<pair<string, string>> tickets) {
// 		vector<string> result;
// 		if (tickets.empty()) return result;
// 		unordered_map<string, unordered_set<string>> graph;
// 		for (const auto &i : tickets) graph[i.first].insert(i.second);
// 		vector<string> result;
// 		result.push_back("JFK");
// 		this->backTrack(result, result, tickets.size(), tickets, graph);
// 		return result;
// 	}
// private:
// 	void backTrack(vector<string>& result, vector<string>& result, const size_t numberOfTickets, vector<pair<string, string>>& tickets, unordered_map<string, unordered_set<string>>& graph) {
// 		if (tickets.empty()) {
// 			if (result.empty() || result < result) result = result;
// 			return;
// 		}
// 		for (const auto& i : graph[result.back()]) {
// 			pair<string, string> x = make_pair(result.back(), i);
// 			auto it = find(begin(tickets), end(tickets), x);
// 			if (it == end(tickets)) continue;
// 			result.push_back(i);
// 			tickets.erase(it);
// 			this->backTrack(result, result, numberOfTickets, tickets, graph);
// 			result.pop_back();
// 			tickets.push_back(x);
// 		}
// 	}
// };
// END: Time Limit Exceeded
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<string> findItinerary(vector<pair<string, string>> tickets) {
// 		vector<string> result;
// 		if (tickets.empty()) return result;
// 		unordered_map<string, unordered_set<string>> graph;
// 		for (const auto &i : tickets) graph[i.first].insert(i.second);
// 		vector<string> result;
// 		result.push_back("JFK");
// 		this->backTrack(result, result, tickets.size(), 0, tickets, graph);
// 		return result;
// 	}
// private:
// 	void backTrack(vector<string>& result, vector<string>& result, const size_t numberOfTickets, const size_t start, vector<pair<string, string>>& tickets, unordered_map<string, unordered_set<string>>& graph) {
// 		if (result.size() == (numberOfTickets + 1)) {
// 			if (result.empty() || result < result) result = result;
// 			return;
// 		}
// 		for (const auto& i : graph[result.back()]) {
// 			pair<string, string> x = make_pair(result.back(), i);
// 			size_t j = 0;
// 			for (j = start; j < numberOfTickets; j++)
// 			    if (tickets[j] == x)
// 			        break;
// 			if (j == numberOfTickets) continue;
// 			swap(tickets[start], tickets[j]);
// 			result.push_back(i);
// 			this->backTrack(result, result, numberOfTickets, start + 1, tickets, graph);
// 			result.pop_back();
// 			swap(tickets[start], tickets[j]);
// 		}
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	vector<pair<string, string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	for (const auto &i : solution.findItinerary(tickets)) cout << i << '\t';
	cout << "\tPassed\n";
	tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
	for (const auto &i : solution.findItinerary(tickets)) cout << i << '\t';
	cout << "\tPassed\n";
	tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
	for (const auto &i : solution.findItinerary(tickets)) cout << i << '\t';
	cout << "\tPassed\n";
	tickets = {{"AXA", "EZE"}, {"EZE", "AUA"}, {"ADL", "JFK"}, {"ADL", "TIA"}, {"AUA", "AXA"}, {"EZE", "TIA"}, {"EZE", "TIA"}, {"AXA", "EZE"}, {"EZE", "ADL"}, {"ANU", "EZE"}, {"TIA", "EZE"}, {"JFK", "ADL"}, {"AUA", "JFK"}, {"JFK", "EZE"}, {"EZE", "ANU"}, {"ADL", "AUA"}, {"ANU", "AXA"}, {"AXA", "ADL"}, {"AUA", "JFK"}, {"EZE", "ADL"}, {"ANU", "TIA"}, {"AUA", "JFK"}, {"TIA", "JFK"}, {"EZE", "AUA"}, {"AXA", "EZE"}, {"AUA", "ANU"}, {"ADL", "AXA"}, {"EZE", "ADL"}, {"AUA", "ANU"}, {"AXA", "EZE"}, {"TIA", "AUA"}, {"AXA", "EZE"}, {"AUA", "SYD"}, {"ADL", "JFK"}, {"EZE", "AUA"}, {"ADL", "ANU"}, {"AUA", "TIA"}, {"ADL", "EZE"}, {"TIA", "JFK"}, {"AXA", "ANU"}, {"JFK", "AXA"}, {"JFK", "ADL"}, {"ADL", "EZE"}, {"AXA", "TIA"}, {"JFK", "AUA"}, {"ADL", "EZE"}, {"JFK", "ADL"}, {"ADL", "AXA"}, {"TIA", "AUA"}, {"AXA", "JFK"}, {"ADL", "AUA"}, {"TIA", "JFK"}, {"JFK", "ADL"}, {"JFK", "ADL"}, {"ANU", "AXA"}, {"TIA", "AXA"}, {"EZE", "JFK"}, {"EZE", "AXA"}, {"ADL", "TIA"}, {"JFK", "AUA"}, {"TIA", "EZE"}, {"EZE", "ADL"}, {"JFK", "ANU"}, {"TIA", "AUA"}, {"EZE", "ADL"}, {"ADL", "JFK"}, {"ANU", "AXA"}, {"AUA", "AXA"}, {"ANU", "EZE"}, {"ADL", "AXA"}, {"ANU", "AXA"}, {"TIA", "ADL"}, {"JFK", "ADL"}, {"JFK", "TIA"}, {"AUA", "ADL"}, {"AUA", "TIA"}, {"TIA", "JFK"}, {"EZE", "JFK"}, {"AUA", "ADL"}, {"ADL", "AUA"}, {"EZE", "ANU"}, {"ADL", "ANU"}, {"AUA", "AXA"}, {"AXA", "TIA"}, {"AXA", "TIA"}, {"ADL", "AXA"}, {"EZE", "AXA"}, {"AXA", "JFK"}, {"JFK", "AUA"}, {"ANU", "ADL"}, {"AXA", "TIA"}, {"ANU", "AUA"}, {"JFK", "EZE"}, {"AXA", "ADL"}, {"TIA", "EZE"}, {"JFK", "AXA"}, {"AXA", "ADL"}, {"EZE", "AUA"}, {"AXA", "ANU"}, {"ADL", "EZE"}, {"AUA", "EZE"}};
	for (const auto &i : solution.findItinerary(tickets)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
