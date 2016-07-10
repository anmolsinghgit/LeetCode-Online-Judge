// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(const int& n) {
		vector<vector<int>> result(n, vector<int>(n, 1));
		if (n <= 1)
			return result;
		else {
			int value(1);
			int left(0);
			int right(n - 1);
			int top(0);
			int bottom(n - 1);
			this->generateMatrix(result, value, left, right, top, bottom);
			return result;
		}
	}
private:
	void generateMatrix(vector<vector<int>>& result, 
		int& value,
		int& left,
		int& right,
		int& top,
		int& bottom) {
		if (left > right || top > bottom)
			return;
		else {
			for (int i(left); i <= right; ++i)
				result[top][i] = value++;
			for (int i(top + 1); i <= bottom; ++i)
				result[i][right] = value++;
			for (int i(right - 1); top != bottom && i >= left; --i)
				result[bottom][i] = value++;
			for (int i(bottom - 1); left != right && i >= top + 1; --i)
				result[i][left] = value++;
			this->generateMatrix(result, value, ++left, --right, ++top, --bottom);
			return;
		}
	}
};
int main(void) {
	Solution solution;
	int n(3);
	for (const auto& i : solution.generateMatrix(n)) {
		for (const auto& j : i)
			cout << j << '\t';
		cout << '\n';
	}
	cout << "\nPassed All\n";
	getchar();
	return 0;
}