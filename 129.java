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
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }
    public int dfs(TreeNode root, int sum) {
        if (root == null)   return 0;
        int nowValue = sum * 10 + root.val;
        if (root.left == null && root.right == null) {
            return nowValue;
        }
        if (root.left != null && root.right != null) {
            return dfs(root.left, nowValue) + dfs(root.right, nowValue);
        } else if (root.left != null) {
            return dfs(root.left, nowValue);
        } else {
            return dfs(root.right, nowValue);
        }
    }
}