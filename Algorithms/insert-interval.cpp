#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(const int& s, const int& e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, const Interval& newInterval) {
		intervals.push_back(newInterval);
		if (intervals.size() <= 1)
			return intervals;
		sort(begin(intervals), end(intervals), this->comp);
		this->merge(0, intervals);
		return intervals;
	}
private:
	void merge(const int& i, vector<Interval>& intervals) {
		if (i + 1 == intervals.size())
			return;
		else {
			if (intervals[i].end >= intervals[i + 1].start) {
				intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
				intervals.erase(begin(intervals) + i + 1);
				this->merge(i, intervals);
				return;
			}
			else {
				this->merge(i + 1, intervals);
				return;
			}
		}
	}
private:
	static bool comp(const Interval& a, const Interval& b) {return a.start < b.start;}
};
int main(void) {
	Solution solution;
	cout << "\nPassed\n";
	getchar();
	return 0;
}