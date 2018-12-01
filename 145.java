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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        dfs(root, list);
        return list;
    }
    public void dfs(TreeNode root, List<Integer> list) {
        if (root == null)   return;
        dfs(root.left, list);
        dfs(root.right, list);
        list.add(root.val);
    }
}