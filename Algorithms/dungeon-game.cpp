// 174. Dungeon Game
// https://leetcode.com/problems/dungeon-game/
// http://www.cnblogs.com/jcliBlogger/p/4764126.html
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
// class Solution {
// public:
// 	int calculateMinimumHP(vector<vector<int>>& dungeon) {
// 		const int p = dungeon.size();
// 		const int q = dungeon.front().size();
// 		vector<vector<int>> OPT(p + 1, vector<int>(q + 1, numeric_limits<int>::max()));
// 		OPT[p][q - 1] = 1;
// 		for (int i = p - 1; i >= 0; --i)
// 			for (int j = q - 1; j >= 0; --j)
// 				OPT[i][j] = max(1, min(OPT[i + 1][j], OPT[i][j + 1]) - dungeon[i][j]);
// 		return OPT[0][0];
// 	}
// };
// class Solution {
// public:
// 	int calculateMinimumHP(vector<vector<int>>& dungeon) {
// 		const int p = dungeon.size();
// 		const int q = dungeon.front().size();
// 		vector<vector<int>> OPT(p + 1, vector<int>(q + 1, numeric_limits<int>::max()));
// 		OPT[p - 1][q] = 1;
// 		for (int i = p - 1; i >= 0; --i)
// 			for (int j = q - 1; j >= 0; --j)
// 				OPT[i][j] = max(1, min(OPT[i + 1][j], OPT[i][j + 1]) - dungeon[i][j]);
// 		return OPT[0][0];
// 	}
// };
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		const int p = dungeon.size();
		const int q = dungeon.front().size();
		vector<int> OPT(q + 1, numeric_limits<int>::max());
		OPT[q - 1] = 1;
		for (int i = p - 1; i >= 0; --i)
			for (int j = q - 1; j >= 0; --j)
				OPT[j] = max(1, min(OPT[j], OPT[j + 1]) - dungeon[i][j]);
		return OPT[0];
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
	cout << solution.calculateMinimumHP(dungeon) << "\tPassed\n";
	dungeon = {{-3, 5}};
	cout << solution.calculateMinimumHP(dungeon) << "\tPassed\n";
	dungeon = {{1, -3, 3}, {0, -2, 0}, {-3, -3,  -3}};
	cout << solution.calculateMinimumHP(dungeon) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}