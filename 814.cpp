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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL)   return root;
        dfs(root);
        return root;
    }
    bool dfs (TreeNode *rt) {
        if (rt == NULL) return false;
        bool a, b;
        a = dfs(rt->left);
        if (!a) rt->left = NULL;
        b = dfs(rt->right);
        if (!b) rt->right = NULL;
        return a || b || (rt->val == 1 ? true : false);
    }
};