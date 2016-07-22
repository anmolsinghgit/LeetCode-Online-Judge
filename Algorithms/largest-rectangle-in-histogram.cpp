// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		vector<int> stack;
		int i = 0;
		int resullt = 0;
		heights.push_back(0);
		while (i < heights.size()) {
			if (stack.empty() || heights[i] > heights[stack.back()]) {
				stack.push_back(i);
				++i;
			}
			else {
				int top = stack.back();
				stack.pop_back();
				resullt = max(resullt, heights[top] * (stack.empty() ? i : i - stack.back() - 1));
			}
		}
		return resullt;
	}
};
int main(void) {
	Solution solution;
	vector<int> heights = {2,1,5,6,2,3};
	if (solution.largestRectangleArea(heights) == 10) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	return 0;
}