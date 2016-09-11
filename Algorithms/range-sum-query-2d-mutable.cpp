// 308. Range Sum Query 2D - Mutable
// https://leetcode.com/problems/range-sum-query-2d-mutable/
// https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		if (matrix.empty()) return;
		this->tree.resize(matrix.size() + 1, vector<int>(matrix.front().size() + 1, 0));
		for (size_t i = 0; i < matrix.size(); ++i)
			for (size_t j = 0; j < matrix.front().size(); ++j)
				this->add(i + 1, j + 1, matrix[i][j]);
	}

	void update(int row, int col, int val) {
		this->add(row + 1, col + 1, val - this->readSingle(row + 1, col + 1));
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return this->read(row2 + 1, col2 + 1) + this->read(row1, col1) - this->read(row2 + 1, col1) - this->read(row1, col2 + 1);
	}
private:
	vector<vector<int>> tree;
	int read(size_t row, size_t col) {
		int result = 0;
		for (size_t i = row; i; i -= i & (-i))
			for (size_t j = col; j; j -= j & (-j))
				result += this->tree[i][j];
		return result;
	}
	int readSingle(size_t row, size_t col) {
		int result = this->tree[row][col];
		if (!row || !col) return result;
		size_t rowBound = row - (row & (-row)), colBound = col - (col & (-col));
		for (size_t i = row - 1; i - rowBound; i -= i & (-i))
			for (size_t j = col; j - colBound; j -= j & (-j))
				result -= this->tree[i][j];
		for (size_t i = row; i - rowBound; i -= i & (-i))
			for (size_t j = col - 1; j - colBound; j -= j & (-j))
				result -= this->tree[i][j];
		for (size_t i = row - 1; i - rowBound; i -= i & (-i))
			for (size_t j = col - 1; j - colBound; j -= j & (-j))
				result += this->tree[i][j];
		return result;
	}
	void add(size_t row, size_t col, int val) {
		for (size_t i = row; i < this->tree.size(); i += i & (-i))
			for (size_t j = col; j < this->tree.front().size(); j += j & (-j))
				this->tree[i][j] += val;
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(void) {
	vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
	NumMatrix numMatrix(matrix);
	cout << numMatrix.sumRegion(2, 1, 4, 3) << "\tPassed\n";
	numMatrix.update(3, 2, 2);
	cout << numMatrix.sumRegion(2, 1, 4, 3) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}