/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)   return true;
        return dfs(root.left, root.right);
    }
    public boolean dfs(TreeNode u, TreeNode v) {
        if (u == null || v == null) {
            return (u == null && v == null);
        }
        if (u.val != v.val) return false;
        return dfs(u.left, v.right) && dfs(u.right, v.left);
    }
}