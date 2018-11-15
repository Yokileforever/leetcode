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
    private int totalSum;
    public int rangeSumBST(TreeNode root, int L, int R) {
        dfs(root, L, R);
        return totalSum;
    }
    public void dfs(TreeNode root, int L, int R) {
        if (root == null)   return;
        if (root.val >= L && root.val <= R) {
            totalSum += root.val;
        }
        dfs(root.left, L, R);
        dfs(root.right, L, R);
    }
}