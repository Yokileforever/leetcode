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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if (root == null)   return ans;
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        Q.add(root);
        while (Q.size() > 0) {
            List<Integer> list = new ArrayList<Integer>();
            int n = Q.size();
            while ((--n) >= 0) {
                TreeNode node = Q.element();
                if (node.left != null) {
                    Q.add(node.left);
                }
                if (node.right != null) {
                    Q.add(node.right);
                }
                list.add(node.val);
                Q.remove();
            }
            ans.add(list);
        }
        Collections.reverse(ans);
        return ans;
    }
}