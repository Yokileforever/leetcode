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
    private int minx = 1000000000;
    public int minDepth(TreeNode root) {
        if (root == null)   return 0;
        dfs(root, 1);
        return minx;
    }
    public void dfs(TreeNode rt, int level) {
        if (rt == null) return;
        if (rt.left == null && rt.right == null) {
            minx = Math.min(minx, level);
        }
        dfs(rt.left, level + 1);
        dfs(rt.right, level + 1);
        return;
    }
}