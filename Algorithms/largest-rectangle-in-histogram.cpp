// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		stack<int> s;
		int result = 0;
		for (int i = 0; i < (int)heights.size(); ) {
			if (s.empty() || heights[i] > heights[s.top()])
				s.push(i++);
			else {
				int top = s.top();
				s.pop();
				result = max(result, heights[top] * (s.empty() ? i : (i - s.top() - 1)));
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> heights = {2,1,5,6,2,3};
	cout << solution.largestRectangleArea(heights) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}