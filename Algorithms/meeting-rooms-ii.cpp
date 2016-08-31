// 253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/
// https://discuss.leetcode.com/topic/27444/concise-c-solution-with-min_heap-sort-greedy
// https://discuss.leetcode.com/topic/20958/ac-java-solution-using-min-heap
// Algorithm Design by Jon Kleinberg and Éva Tardos
// https://discuss.leetcode.com/topic/20958/ac-java-solution-using-min-heap
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		if (intervals.empty()) return 0;
		sort(begin(intervals), end(intervals), [](Interval& a, Interval& b) {return a.start < b.start;});
		priority_queue<int, vector<int>, greater<int>> pq;
		for (size_t i = 0; i < intervals.size(); ++i) {
			if (!pq.empty() && pq.top() <= intervals[i].start) pq.pop();
			pq.push(intervals[i].end);
		}
		return pq.size();
	}
};
// class Solution {
// public:
// 	int minMeetingRooms(vector<Interval>& intervals) {
// 		sort(begin(intervals), end(intervals), less);
// 		int result = 0;
// 		for (size_t i = 0; i < intervals.size(); ++i) {
// 			int depth = 1;
// 			for (size_t j = 0; j < i; ++j) {
// 				depth += intervals[j].end > intervals[i].start;
// 			}
// 			result = max(result, depth);
// 		}
// 		return result;
// 	}
// private:
// 	static bool less(Interval& a, Interval& b) {return a.start < b.start;}
// };
int main(void) {
	Solution solution;
	vector<Interval> intervals = {{0, 30}, {5, 10}, {15, 20}};
	cout << solution.minMeetingRooms(intervals) << "\tPassed\n";
	intervals.clear();
	cout << solution.minMeetingRooms(intervals) << "\tPassed\n";
	intervals = {{9, 10}, {4, 9}, {4, 17}};
	cout << solution.minMeetingRooms(intervals) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}