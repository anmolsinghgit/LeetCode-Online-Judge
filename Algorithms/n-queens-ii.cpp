// 52. N-Queens II
// https://leetcode.com/problems/n-queens-ii/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int totalNQueens(const int& n) {
		int result(0);
		vector<int> column(n, 0);
		vector<int> mainDiagonal(2 * n - 1, 0);
		vector<int> antiDiagonal(2 * n - 1, 0);
		this->totalNQueens(0, n, result, column, mainDiagonal, antiDiagonal);
		return result;
	}
private:
	void totalNQueens(const int& r, const int& n, int& result, vector<int>& column, vector<int>& mainDiagonal, vector<int>& antiDiagonal) {
		if (r == n) {
			++result;
			return;
		}
		else {
			for (int i(0); i < n; ++i) {
				if (!column[i] && !mainDiagonal[r + i] && !antiDiagonal[n - 1 - r + i]) {
					column[i] = 1;
					mainDiagonal[r + i] = 1;
					antiDiagonal[n - 1 - r + i] = 1;
					this->totalNQueens(r + 1, n, result, column, mainDiagonal, antiDiagonal);
					column[i] = 0;
					mainDiagonal[r + i] = 0;
					antiDiagonal[n - 1 - r + i] = 0;					
				}
				else
					continue;
			}
			return;
		}
	}
};
int main(void) {
	Solution solution;
	vector<int> a;
	vector<int> b;
	a.push_back(1);
	b.push_back(1);
	a.push_back(2);
	b.push_back(0);
	for (int i(0); i < b.size(); ++i) {
		if (b[i] ^ solution.totalNQueens(a[i])) {
			cout << "\nError\n";
			getchar();
			return 0;
		}
	}
	cout << "\nPassed\n";
	getchar();
	return 0;
}