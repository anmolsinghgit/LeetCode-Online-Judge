// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// https://discuss.leetcode.com/topic/3158/my-accepted-java-solution
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
	TreeNode* sortedArrayToBST(const vector<int>& nums) {
		if (nums.empty()) return NULL;
		return this->sortedArrayToBST(0, nums.size() - 1, nums);
	}
private:
	TreeNode* sortedArrayToBST(const int& i, const int& j, const vector<int>& nums) {
		if (i > j) return NULL;
		int mid = (i + j) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = this->sortedArrayToBST(i, mid - 1, nums);
		root->right = this->sortedArrayToBST(mid + 1, j, nums);
		return root;
	}	
};
void inorderTraversal(TreeNode *root) {
	if (!root) return;
	inorderTraversal(root->left);
	cout << root->val << '\t';
	inorderTraversal(root->right);
	return;
}
int main(void) {
	Solution solution;
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	TreeNode *root = solution.sortedArrayToBST(nums);
	inorderTraversal(root);
	cout << "\nPassed\n";
	cout << "\nPassed All\n";	
	return 0;
}