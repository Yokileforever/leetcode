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
    private boolean f = true;
    public boolean isBalanced(TreeNode root) {
        Integer minx, maxn;
//      Boolean f = true;
        dfs(root);
        return f;
    }
    public int dfs(TreeNode rt) {
        if (rt == null) return 0;
//        System.out.println(f);
        int x = dfs(rt.left);
        int y = dfs(rt.right);
        if (Math.abs(x - y) > 1) {
            f = false;
        }
        return Math.max(x, y) + 1;
    }
}