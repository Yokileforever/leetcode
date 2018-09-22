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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if (root == null)   return ans;
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        Q.add(root);
        while (Q.size() > 0) {
            Object[] tmp = Q.toArray();
            Q.clear();
            List<Integer> list = new ArrayList<Integer>();
            for (int i = 0; i < tmp.length; ++i) {
                TreeNode x = (TreeNode)tmp[i];
                list.add(x.val);
                if (x.left != null)
                    Q.add(x.left);
                if (x.right != null)
                    Q.add(x.right);
            }
            ans.add(list);
        }
        return ans;
    }
}