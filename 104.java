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
    private int level = 1;
    public int maxDepth(TreeNode root) {
        if (root == null)   return 0;
        dfs(root, 1);
        return level;
    }
    public void dfs(TreeNode u, int cnt) {
        if (u == null)  return ;
        level = Math.max(cnt, level);
        dfs(u.left, cnt + 1);
        dfs(u.right, cnt + 1);
    }
}