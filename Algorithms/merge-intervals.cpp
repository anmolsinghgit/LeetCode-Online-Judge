#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(const int& s, const int& e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() <= 1)
			return intervals;
		sort(begin(intervals), end(intervals), this->comp);
		this->merge(0, intervals);
		return intervals;
	}
private:
	static bool comp(const Interval& a, const Interval& b) {return a.start < b.start;}
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
};
int main(void) {
	Solution solution;
	vector<Interval> a;
	vector<Interval> b;
	a.push_back(Interval(1, 3));
	a.push_back(Interval(2, 6));
	a.push_back(Interval(8, 10));
	a.push_back(Interval(15, 18));
	b.push_back(Interval(1, 6));
	b.push_back(Interval(8, 10));
	b.push_back(Interval(15, 18));
	cout << "\nPassed All\n";
	getchar();
	return 0;
}