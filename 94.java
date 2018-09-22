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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        dfs(root, list);
        return list;
    }
    public void dfs(TreeNode u, List<Integer> list) {
        if (u == null)  return;
        dfs(u.left, list);
        list.add(u.val);
        dfs(u.right, list);
    }
}