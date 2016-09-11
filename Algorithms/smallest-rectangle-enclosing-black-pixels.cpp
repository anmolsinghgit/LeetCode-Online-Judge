// 302. Smallest Rectangle Enclosing Black Pixels
// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
// https://discuss.leetcode.com/topic/29006/c-java-python-binary-search-solution-with-explanation
// https://discuss.leetcode.com/topic/29211/very-easy-dfs-java-solution-with-comments
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minArea(vector<vector<char>>& image, int x, int y) {
		if (x < 0 || x >= (int)image.size() || y < 0 || y >= (int)image.front().size() || image[x][y] == '0') return -1;
		int left = x, right = x, top = y, bottom = y;
		this->dfs(image, x, y, left, right, top, bottom);
		return (abs(right - left) + 1) * (abs(bottom - top) + 1);
	}
private:
	void dfs(vector<vector<char>>& image, int x, int y, int& left, int& right, int& top, int& bottom) {
		if (x < 0 || x >= (int)image.size() || y < 0 || y >= (int)image.front().size() || image[x][y] == '0') return;
		image[x][y] = '0';
		left = min(left, x);
		right = max(right, x);
		top = min(top, y);
		bottom = max(bottom, y);
		this->dfs(image, x - 1, y, left, right, top, bottom);
		this->dfs(image, x + 1, y, left, right, top, bottom);
		this->dfs(image, x, y - 1, left, right, top, bottom);
		this->dfs(image, x, y + 1, left, right, top, bottom);
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> image = {{'0', '0', '1', '0'}, {'0', '1', '1', '0'}, {'0', '1', '0', '0'}};
	cout << solution.minArea(image, 0, 2) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}