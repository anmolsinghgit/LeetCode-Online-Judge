// 55. Jump Game
// https://leetcode.com/problems/jump-game/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool canJump(const vector<int>& nums) {
		int i(0);
		if (i + nums[i] >= nums.size() - 1)
			return true;
		else {

			while (i + nums[i] < nums.size() - 1) {
				int nextI(-1);
				int maxRight(-1);
				for (int j(1);  j <= nums[i]; ++j) {
					if (i + j + nums[i + j] > maxRight) {
						maxRight = i + j + nums[i + j];
						nextI = i + j;
					}
				}
				if (i >= nextI)
					return false;
				else
					i = nextI;
			}
			return true;
		}
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> A;
	vector<bool> b;
	A.push_back(vector<int>({2,3,1,1,4}));
	b.push_back(true);
	A.push_back(vector<int>({3,2,1,0,4}));
	b.push_back(false);
	for (size_t i(0); i < b.size(); ++i) {
		if (b[i] ^ solution.canJump(A[i])) {
			cout << "\nError\n";
			getchar();
			return 0;
		}
		else
			cout << "\nPassed\n";
	}
	cout << "\nPassed All\n";
	getchar();
	return 0;
}