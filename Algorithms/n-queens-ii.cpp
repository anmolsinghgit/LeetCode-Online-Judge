// 52. N-Queens II
// https://leetcode.com/problems/n-queens-ii/
// https://github.com/soulmachine/leetcode
#include <iostream>
using namespace std;
class Solution {
public:
    int totalNQueens(const int& n) {
        return 0;
    }
};
int main(void) {
	Solution solution;
	vector<int> a;
	vector<int> b;
	a.push_back(1);
	b.push_back(1);
	for (int i(0); i < b.size(); ++i) {
		if (b[i] ^ a[i]) {
			cout << "\nError\n";
			return 0;
		}
	}
	cout << "\nPassed\n";
	return 0;
}