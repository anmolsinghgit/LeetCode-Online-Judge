// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
// https://leetcode.com/discuss/16171/sharing-my-simple-c-code-o-n-time-o-1-space
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int trap(const vector<int>& height) {
		int result(0);
		int left(0);
		int right(height.size() - 1);
		int maxleft(0);
		int minright(0);
		while(left <= right) {
			if (height[left] <= height[right]) {
				if (height[left] < maxleft) {
					result += maxleft - height[left];
					++left;
				}
				else {
					maxleft = height[left];
					++left;
				}
			}
			else {
				if (height[right] < minright) {
					result += minright - height[right];
					--right;
				}
				else {
					minright = height[right];
					--right;
				}
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> height({0,1,0,2,1,0,1,3,2,1,2,1});
	cout << solution.trap(height);
	cout << "\nPassed\n";
	return 0;
}
