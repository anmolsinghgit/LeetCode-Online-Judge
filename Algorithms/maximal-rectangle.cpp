// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/
// https://siddontang.gitbooks.io/leetcode-solution/content/array/maximal_rectangle.html
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty()) {
			return 0;
		}
		const int m = matrix.size();
		const int n = matrix.front().size();
		vector<vector<int>> histgramMatrix(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0') {
					histgramMatrix[i][j] = 0;
				}
				else {
					histgramMatrix[i][j] = (i == 0 ? 1 : histgramMatrix[i - 1][j] + 1);
				}
			}
		}
		int result = 0;
		for (auto& i : histgramMatrix) {
			result = max(result, this->largestRectangleArea(i));
		}
		return result;
	}
private:
	int largestRectangleArea(vector<int>& nums) {
		nums.push_back(0);
		int result = 0;
		int i = 0;
		vector<int> stack;
		while (i < nums.size()) {
			if (stack.empty() || nums[stack.back()] < nums[i]) {
				stack.push_back(i++);
			}
			else {
				int top = stack.back();
				stack.pop_back();
				result = max(result, nums[top] * (stack.empty() ? i : i - stack.back() - 1));
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> matrix = {
									{'1', '0', '1', '0', '0'},
									{'1', '0', '1', '1', '1'},
									{'1', '1', '1', '1', '1'},
									{'1', '0', '0', '1', '0'}
									};
	if (solution.maximalRectangle(matrix) == 6) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	return 0;
}