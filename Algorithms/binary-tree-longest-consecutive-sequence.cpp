// 298. Binary Tree Longest Consecutive Sequence
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// https://leetcode.com/articles/binary-tree-longest-consecutive-sequence/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// BEGIN: Top-down Apporach
class Solution {
public:
	int longestConsecutive(TreeNode* root) {
		int result = 0;
		this->dfs(root, NULL, 0, result);
		return result;
	}
private:
	void dfs(TreeNode* current, TreeNode* parent, int length, int &result) {
		if (!current) return;
		length = (parent && parent->val + 1 == current->val) ? length + 1 : 1;
		result = max(result, length);
		this->dfs(current->left, current, length, result);
		this->dfs(current->right, current, length, result);
	}	
};
// END: Top-down Apporach
// BEGIN: Top-down Apporach
// class Solution {
// public:
// 	int longestConsecutive(TreeNode* root) {
// 		return this->dfs(root, NULL, 0);
// 	}
// private:
// 	int dfs(TreeNode* current, TreeNode* parent, int length) {
// 		if (!current) return 0;
// 		length = (parent && parent->val + 1 == current->val) ? length + 1 : 1;
// 		return max(length, max(this->dfs(current->left, current, length), this->dfs(current->right, current, length)));
// 	}
// };
// END: Top-down Apporach
// BEGIN: Top-down Apporach
// class Solution {
// public:
// 	int longestConsecutive(TreeNode* root) {
// 		int result = 0;
// 		this->longestConsecutive(root, 0, INT_MIN, 0, result);
// 		return result;
// 	}
// private:
// 	void longestConsecutive(TreeNode* root, int previousState, int previousValue, int previousLength, int& result) {
// 		if (!root) return;
// 		if (previousValue == INT_MIN) {
// 			result = max(result, 1);
// 			this->longestConsecutive(root->left, 0, root->val, 1, result);
// 			this->longestConsecutive(root->right, 0, root->val, 1, result);
// 			return;
// 		}
// 		if (previousState == 0) {
// 			if (previousValue + 1 == root->val) {
// 				result = max(result, 2);
// 				this->longestConsecutive(root->left, 1, root->val, 2, result);
// 				this->longestConsecutive(root->right, 1, root->val, 2, result);
// 				return;
// 			}
// 			this->longestConsecutive(root->left, 0, root->val, 0, result);
// 			this->longestConsecutive(root->right, 0, root->val, 0, result);
// 			return;		
// 		}
// 		if (previousState == 1) {
// 			if (previousValue + 1 == root->val) {
// 				result = max(result, previousLength + 1);
// 				this->longestConsecutive(root->left, 1, root->val, previousLength + 1, result);
// 				this->longestConsecutive(root->right, 1, root->val, previousLength + 1, result);
// 				return;				
// 			}
// 			this->longestConsecutive(root->left, 0, root->val, 0, result);
// 			this->longestConsecutive(root->right, 0, root->val, 0, result);
// 			return;			
// 		}
// 	}	
// };
// END: Top-down Apporach
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(5);
	cout << solution.longestConsecutive(root) << "\tPassed\n";
	root = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	root->right->left->left = new TreeNode(1);
	cout << solution.longestConsecutive(root) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}