// 120. Triangle
// https://leetcode.com/problems/triangle/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		for (size_t i = triangle.size() - 2; i + 1 > 0; --i) {
			for (size_t j = 0; j < triangle[i].size(); ++j) {
				triangle[i][j] = min(triangle[i + 1][j] + triangle[i][j], triangle[i + 1][j + 1] + triangle[i][j]);
			}
		}
		return triangle[0][0];
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> triangle = {
									{2},
									{3,4},
									{6,5,7},
									{4,1,8,3}
									};
	if (solution.minimumTotal(triangle) == 11) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	triangle = {{2}};
	if (solution.minimumTotal(triangle) == 2) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}