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
    public void flatten(TreeNode root) {
        if (root == null)   return;
        Stack<TreeNode> st = new Stack<TreeNode>();
        TreeNode rt = new TreeNode(-1);
        st.push(root);
        while (!st.empty()) {
            TreeNode tmp = st.pop();
            while (tmp != null) {
                if (tmp.right != null)  st.push(tmp.right);
                rt.right = tmp;
                rt = rt.right;
                tmp = tmp.left;
                rt.left = null;
            }
        }
    }
}