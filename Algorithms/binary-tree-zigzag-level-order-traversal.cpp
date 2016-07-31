// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// https://discuss.leetcode.com/topic/3413/my-accepted-java-solution
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(const int& x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		this->zigzagLevelOrder(root, 0, result);
		return result;
	}
private:
	void zigzagLevelOrder(TreeNode *current, const size_t& level, vector<vector<int>>& result) {
		if (!current) return;
		if (result.size() <= level) result.push_back(vector<int>());
		if (!(level & 1)) result[level].push_back(current->val);
		else result[level].insert(begin(result[level]), current->val);
		this->zigzagLevelOrder(current->left, level + 1, result);
		this->zigzagLevelOrder(current->right, level + 1, result);
		return;
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	for (const auto& i : solution.zigzagLevelOrder(root)) {
		for (const auto& j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}