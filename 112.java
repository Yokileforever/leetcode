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
    private boolean f = false;
    public boolean hasPathSum(TreeNode root, int sum) {
        dfs(root, 0, sum);
        return f;
    }
    public void dfs(TreeNode rt, int now, int target) {
        if (rt == null) return;
        now += rt.val;
        if (rt.left == null && rt.right == null) {
            if (now == target) {
                f = true;
            }
        }
        dfs(rt.left, now, target);
        dfs(rt.right, now, target);
    }
}