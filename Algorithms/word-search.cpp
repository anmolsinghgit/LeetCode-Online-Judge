// 79. Word Search
// https://leetcode.com/problems/word-search/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool exist(const vector<vector<char>>& board, const string& word) {
		vector<vector<int>> path(board.size(), vector<int>(board.front().size(), 0));
		bool result(false);
		this->exist(result, 0, 0, 0, path, board, word);
		return result;
	}
private:
	void exist(bool& result,
		const size_t& start,
		const size_t& row, 
		const size_t& column,
		vector<vector<int>>& path,
		const vector<vector<char>>& board, 
		const string& word) {
		if (word.size() == 0 
			|| board.size() == 0 
			|| word.size() > board.size() * board.front().size()) {
			result = false;
			return;
		}
		if (word.size() == 1) {
			for (const auto& i : board) {
				for (const auto& j : i) {
					if (j == word[0]) {
						result = true;
						return;
					}
				}
			}
			result = false;
			return;
		}
		if (start == word.size() - 1) {
			if (column >= 1
				&& path[row][column - 1] == 0
				&& board[row][column - 1] == word[start]) {
				result = true;
				return;
			}
			if (column + 1 < board.front().size()
				&& path[row][column + 1] == 0
				&& board[row][column + 1] == word[start]) {
				result = true;
				return;
			}
			if (row >= 1
				&& path[row - 1][column] == 0
				&& board[row - 1][column] == word[start]) {
				result = true;
				return;
			}
			if (row + 1 < board.size()
				&& path[row + 1][column] == 0
				&& board[row + 1][column] == word[start]) {
				result = true;
				return;			
			}
			result = false;
			return;
		}
		if (start == 0) {
			for (size_t i(0); i < board.size(); ++i) {
				for (size_t j(0); j < board.front().size(); ++j) {
					if (board[i][j] == word[start]) {
						result = false;
						path[i][j] = 1;
						this->exist(result, start + 1, i, j, path, board, word);
						path[i][j] = 0;
						if (result == true) {
							return;
						}
					}
				}
			}
			result = false;
			return;
		}
		else {
			if (column >= 1
				&& path[row][column - 1] == 0
				&& board[row][column - 1] == word[start]) {
				path[row][column - 1] = 1;
				this->exist(result, start + 1, row, column - 1, path, board, word);
				path[row][column - 1] = 0;
				if (result == true) {
					return;
				}
			}
			if (column + 1 < board.front().size()
				&& path[row][column + 1] == 0
				&& board[row][column + 1] == word[start]) {
				path[row][column + 1] = 1;
				this->exist(result, start + 1, row, column + 1, path, board, word);
				path[row][column + 1] = 0;
				if (result == true) {
					return;
				}
			}
			if (row >= 1
				&& path[row - 1][column] == 0
				&& board[row - 1][column] == word[start]) {
				path[row - 1][column] = 1;
				this->exist(result, start + 1, row - 1, column, path, board, word);
				path[row - 1][column] = 0;
				if (result == true) {
					return;
				}
			}
			if (row + 1 < board.size()
				&& path[row + 1][column] == 0
				&& board[row + 1][column] == word[start]) {
				path[row + 1][column] = 1;
				this->exist(result, start + 1, row + 1, column, path, board, word);
				path[row + 1][column] = 0;
				if (result == true) {
					return;
				}			
			}
			result = false;
			return;
		}
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> board({
								vector<char>({'A','B','C','E'}),
								vector<char>({'S','F','C','S'}),
								vector<char>({'A','D','E','E'})
								});
	string word("ABCCED");
	cout << boolalpha << true << '\t' << solution.exist(board, word) << '\n';
	cout << "\nPassed\n";
	word = "SEE";
	cout << boolalpha << true << '\t' << solution.exist(board, word) << '\n';
	cout << "\nPassed\n";
	word = "ABCB";
	cout << boolalpha << false << '\t' << solution.exist(board, word) << '\n';
	cout << "\nPassed\n";
	board = vector<vector<char>>({
								vector<char>({'a', 'b'}),
								vector<char>({'c', 'd'})
								});
	word = "cabd";
	cout << boolalpha << true << '\t' << solution.exist(board, word) << '\n';
	cout << "\nPassed\n";
	board = vector<vector<char>>({
								vector<char>({'a', 'b', 'c'}),
								vector<char>({'a', 'e', 'd'}),
								vector<char>({'a', 'f', 'g'}),
								});
	word = "abcdefg";
	cout << boolalpha << true << '\t' << solution.exist(board, word) << '\n';
	cout << "\nPassed\n";
	board = vector<vector<char>>({
								vector<char>({'F', 'Y', 'C', 'E', 'N', 'R', 'D'}),
								vector<char>({'K', 'L', 'N', 'F', 'I', 'N', 'U'}),
								vector<char>({'A', 'A', 'A', 'R', 'A', 'H', 'R'}),
								vector<char>({'N', 'D', 'K', 'L', 'P', 'N', 'E'}),
								vector<char>({'A', 'L', 'A', 'N', 'S', 'A', 'P'}),
								vector<char>({'O', 'O', 'G', 'O', 'T', 'P', 'N'}),
								vector<char>({'H', 'P', 'O', 'L', 'A', 'N', 'O'})
							});
	word = "INDIA";
	cout << boolalpha << false << '\t' << solution.exist(board, word) << '\n';
	cout << "\nPassed\n";
	board = vector<vector<char>>({
								vector<char>({'b', 'b'}),
								vector<char>({'a', 'b'}),
								vector<char>({'b', 'a'})
							});
	word = "a";
	cout << boolalpha << true << '\t' << solution.exist(board, word) << '\n';
	cout << "\nPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}