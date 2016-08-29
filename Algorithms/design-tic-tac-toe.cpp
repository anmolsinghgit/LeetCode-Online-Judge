// 348. Design Tic-Tac-Toe
// https://leetcode.com/problems/design-tic-tac-toe/
// https://discuss.leetcode.com/topic/44538/simple-o-1-time-c-solution-following-provided-hints
#include <iostream>
#include <cstring>
using namespace std;
class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n): rows(new int[n]), columns(new int[n]), diagonal(0), antiDiagonal(0), size(n), winner(0) {
		memset(rows, 0, sizeof(int) * n);
		memset(columns, 0, sizeof(int) * n);
	}

	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
			0: No one wins.
			1: Player 1 wins.
			2: Player 2 wins. */
	int move(int row, int col, int player) {
		if (this->winner) return this->winner;
		int hashmap[2] = {-1, 1};
		this->rows[row] += hashmap[player - 1];
		this->columns[col] += hashmap[player - 1];
		if (row == col) this->diagonal += hashmap[player - 1];
		if (row + col == this->size - 1) this->antiDiagonal += hashmap[player - 1];
		for (int i = 0; i < this->size; ++i) {
			if (this->rows[i] == -size || this->columns[i] == -size) return this->winner = 1;
			if (this->rows[i] == size || this->columns[i] == size) return this->winner = 2;
		}
		if (this->diagonal == -size || this->antiDiagonal == -size) return this->winner = 1;
		if (this->diagonal == size || this->antiDiagonal == size) return this->winner = 2;
		return this->winner = 0;
	}
private:
	int *rows;
	int *columns;
	int diagonal;
	int antiDiagonal;
	int size;
	int winner;
};
// class TicTacToe {
// public:
// 	/** Initialize your data structure here. */
// 	TicTacToe(int n): matrix(n, vector<int>(n, 0)), state(0) {}

// 	/** Player {player} makes a move at ({row}, {col}).
// 		@param row The row of the board.
// 		@param col The column of the board.
// 		@param player The player, can be either 1 or 2.
// 		@return The current winning condition, can be either:
// 			0: No one wins.
// 			1: Player 1 wins.
// 			2: Player 2 wins. */
// 	int move(int row, int col, int player) {
// 		if (this->state) return this->state;
// 		this->matrix[row][col] = player;
// 		const int n = this->matrix.size();
// 		vector<bool> checkSum(4, true);
// 		for (int i = 0; i < n; ++i) {
// 			checkSum[0] = checkSum[0] && this->matrix[row][i] == player;
// 			checkSum[1] = checkSum[1] && this->matrix[i][col] == player;
// 			checkSum[2] = checkSum[2] && this->matrix[i][i] == player;
// 			checkSum[3] = checkSum[3] && this->matrix[i][n - 1 - i] == player;
// 		}
// 		for (int i = 0; i < 4; ++i) if (checkSum[i]) return this->state = player;
// 		return this->state = 0;
// 	}
// private:
// 	vector<vector<int>> matrix;
// 	int state;
// };

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

int main(void) {
	// TicTacToe toe(3);
	// cout << toe.move(0, 0, 1) << "\tPassed\n";
	// cout << toe.move(0, 2, 2) << "\tPassed\n";
	// cout << toe.move(2, 2, 1) << "\tPassed\n";
	// cout << toe.move(1, 1, 2) << "\tPassed\n";
	// cout << toe.move(2, 0, 1) << "\tPassed\n";
	// cout << toe.move(1, 0, 2) << "\tPassed\n";
	// cout << toe.move(2, 1, 1) << "\tPassed\n";
	TicTacToe toe(2);
	cout << toe.move(0, 0, 2) << "\tPassed\n";
	cout << toe.move(0, 1, 1) << "\tPassed\n";
	cout << toe.move(1, 1, 2) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}