/*
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (47.44%)
 * Total Accepted:    253.5K
 * Total Submissions: 532.8K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 
 * Given two binary trees, write a function to check if they are the same or
 * not.
 * 
 * 
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:     1         1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * Output: false
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool f = true;
		dfs(p, q, f);
		return f;
	}
	void dfs(TreeNode* a, TreeNode* b, bool &f) {
		if (!f)	return ;
		if (a == NULL && b == NULL)	return ;
		if (a == NULL && b != NULL)	f = false;
		if (a != NULL && b == NULL)	f = false;
		if (!f)	return ;
		if (a->val == b->val) {
			dfs(a->left, b->left, f);
			dfs(a->right, b->right, f);
			if (!f)	return ;
		} else {
			f = false;
			return ;
		}
	} 
};
