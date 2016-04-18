//11. Container With Most Water
//https://leetcode.com/problems/container-with-most-water/
//https://github.com/haoel/leetcode
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxArea(const vector<int>& height) {
		int result = INT_MIN;
		int start = 0;
		int end = height.size() - 1;
		while (start < end) {
			int area = min(height[start], height[end]) * (end - start);
			result = max(result, area);
			if (height[start] <= height[end]) {
				++start;
			}
			else {
				--end;
			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	return 0;
}
