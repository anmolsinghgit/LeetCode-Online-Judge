#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int jump(const vector<int>& nums) {
		int result(0);
		int i(0);
		while (i < nums.size() - 1) {
			if (i + nums[i] >= nums.size() - 1) {
				++result;
				break;
			}
			else {
				int upperbound(-1);
				int nexti(-1);
				for (int j(1); j <= nums[i]; ++j) {
					if (i + j + nums[i + j] > upperbound) {
						upperbound = i + j + nums[i + j];
						nexti = i + j;
					}
				}
				i = nexti;
				++result;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> A;
	vector<int> b;
	A.push_back(vector<int>({ 2,3,1,1,4 }));
	A.push_back(vector<int>({ 4,1,1,3,1,1,1 }));
	b.push_back(2);
	b.push_back(2);
	for (size_t i(0); i < b.size(); ++i) {
		if (b[i] ^ solution.jump(A[i])) {
			cout << "\nError\n";
			getchar();
			return 0;
		}
	}
	cout << "\nPassed\n";
	getchar();
	return 0;
}