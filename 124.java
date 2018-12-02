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
    int finalAns;
    public int maxPathSum(TreeNode root) {
        finalAns = Integer.MIN_VALUE;
        dfs(root);
        return finalAns;
    }
    public int dfs(TreeNode root) {
        if (root == null)   return 0;
        int left = dfs(root.left);
        int right = dfs(root.right);
        finalAns = Math.max(left + right + root.val, finalAns);
        int ans = Math.max(left + root.val, right + root.val);
        ans = Math.max(ans, root.val);
        finalAns = Math.max(finalAns, ans);
        return ans;
    }
}