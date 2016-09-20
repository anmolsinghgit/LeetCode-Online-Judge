// 401. Binary Watch
// https://leetcode.com/problems/binary-watch/
// https://discuss.leetcode.com/topic/59373/0ms-c-back-tracking-solution-easy-to-understand
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		this->backTracking(result, num, 0, 0, 0);
		return result;
	}
private:
	void backTracking(vector<string>& result, int num, int hour, int minute, int idx) {
		if (hour > 11 || minute > 59 || num < 0) return;
		if (num == 0) {
			string s = to_string(hour) + ':' + ((minute < 10) ? ('0' + to_string(minute)) : to_string(minute));
			result.push_back(s);
			return;
		}
		for (int i = idx; i < 10; ++i) {
			if (i < 4)
				this->backTracking(result, num - 1, hour + (1 << i), minute, i + 1);
			else
				this->backTracking(result, num - 1, hour, minute + (1 << (i - 4)), i + 1);
		}
	}
};
int main(void) {
	Solution solution;
	for (const auto &i : solution.readBinaryWatch(1)) cout << i << '\t';
	cout << "\nPassed\n";
	for (const auto &i : solution.readBinaryWatch(2)) cout << i << '\t';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}