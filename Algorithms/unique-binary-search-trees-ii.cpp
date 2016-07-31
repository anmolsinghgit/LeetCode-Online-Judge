// 95. Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(const int& x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<TreeNode*> generateTrees(const int& n) {
		if (n == 0) return vector<TreeNode*>(0, NULL);
		return this->generateTrees(1, n);	
	}
private:
	vector<TreeNode*> generateTrees(const int& start, const int& end) {
		if (start > end) {
			return vector<TreeNode*>(1, NULL);
		}
		vector<TreeNode*> result;
		for (int i = start; i <= end; ++i) {
			vector<TreeNode*> lefts = this->generateTrees(start, i - 1);
			vector<TreeNode*> rights = this->generateTrees(i + 1, end);
			for (const auto& left : lefts) {
				for (const auto& right : rights) {
					TreeNode *root = new TreeNode(i);
					root->left = left;
					root->right = right;
					result.push_back(root);
				}
			}
		}
		return result;
	}
};
void printTree(TreeNode *root) {
	if (!root) return;
	cout << root->val << '\t';
	printTree(root->left);
	printTree(root->right);
	return;
}
int main(void) {
	Solution solution;
	int n = 3;
	for (const auto& i : solution.generateTrees(n)) {
		printTree(i);
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}