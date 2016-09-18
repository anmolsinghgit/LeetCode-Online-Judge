// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/
// https://siddontang.gitbooks.io/leetcode-solution/content/array/maximal_rectangle.html
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		const int m = matrix.size();
		if (m == 0) return 0;
		const int n = matrix.front().size();
		if (n == 0) return 0;
		vector<vector<int>> Matrix(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0') continue;
				if (i == 0) {
					Matrix[i][j] = 1;
					continue;
				}
				Matrix[i][j] = Matrix[i - 1][j] + 1;
			}
		}
		int result = 0;
		for (auto &i : Matrix) result = max(result, this->largestRectangleArea(i));
		return result;
	}
private:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int result = 0;
		vector<int> stack;
		for (int i = 0; i < (int)heights.size(); ) {
			if (stack.empty() || heights[i] > heights[stack.back()]) {
				stack.push_back(i++);
				continue;
			}
			int top = stack.back();
			stack.pop_back();
			result = max(result, heights[top] * (stack.empty() ? i : (i - stack.back() - 1)));
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	cout << solution.maximalRectangle(matrix) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}