// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(const vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.empty())
			return result;
		else {
			int left(0);
			int right(matrix.front().size());
			int top(0);
			int bottom(matrix.size());
			this->spiralOrder(result, left, --right, top, --bottom, matrix);
			return result;
		}
	}
private:
	void spiralOrder(vector<int>& result,
		const int& left, 
		const int& right, 
		const int& top, 
		const int& bottom, 
		const vector<vector<int>>& matrix) {
		if (left > right || top > bottom)
			return;
		else {
			for (int i(left); i <= right; ++i)
				result.push_back(matrix[top][i]);
			for (int i(top + 1); i <= bottom; ++i)
				result.push_back(matrix[i][right]);
			for (int i(right - 1); top != bottom && i >= left; --i)
				result.push_back(matrix[bottom][i]);
			for (int i(bottom - 1); left != right && i >= top + 1; --i)
				result.push_back(matrix[i][left]);
			this->spiralOrder(result, left + 1, right - 1, top + 1, bottom - 1, matrix);
			return;
		}
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> A;
	vector<int> b({1,2,3,6,9,8,7,4,5});
	A.push_back(vector<int>({1, 2, 3}));
	A.push_back(vector<int>({4, 5, 6}));
	A.push_back(vector<int>({7, 8, 9}));
	if (solution.spiralOrder(A) != b) {
		cout << "\nError\n";
		getchar();
		return 0;
	}
	else
		cout << "\nPassed\n";
	A.clear();
	b.clear();
	if (solution.spiralOrder(A) != b) {
		cout << "\nError\n";
		getchar();
		return 0;
	}
	else
		cout << "\nPassed\n";
	A.clear();
	b.clear();
	A.push_back(vector<int>{2, 3});
	b = {2, 3};
	if (solution.spiralOrder(A) != b) {
		cout << "\nError\n";
		getchar();
		return 0;
	}
	else
		cout << "\nPassed\n";
	cout << "\nPassed All\n";
	getchar();
	return 0;	
}