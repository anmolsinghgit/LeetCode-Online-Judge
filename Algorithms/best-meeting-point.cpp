// 296. Best Meeting Point
// https://leetcode.com/problems/best-meeting-point/
// https://discuss.leetcode.com/topic/28150/am-i-the-only-person-who-don-t-know-why-median-could-give-shortest-distance
// http://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations
// https://discuss.leetcode.com/topic/27710/14ms-java-solution/3
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		vector<int> X;
		vector<int> Y;
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid.front().size(); ++j) {
				if (grid[i][j]) {
					X.push_back(i);
					Y.push_back(j);
				}
			}
		}
		return this->minTotalDistance(X) + this->minTotalDistance(Y);
	}
private:
	int minTotalDistance(vector<int>& axis) {
		sort(begin(axis), end(axis));
		int result = 0;
		for (size_t i = 0, j = axis.size() - 1; i < j; ++i, --j) result += axis[j] - axis[i];
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> grid = {{1, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
	cout << solution.minTotalDistance(grid) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}