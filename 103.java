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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (root == null)   return list;
        queue.add(root);
        int turn = 0;
        while (queue.size() > 0) {
            List<Integer> tmp = new ArrayList<Integer>();
            int n = queue.size();
            while (n > 0) {
                n--;
                TreeNode x = queue.getFirst();
                tmp.add(x.val);
                if (x.left != null) queue.add(x.left);
                if (x.right != null)    queue.add(x.right);
                queue.removeFirst();
            }
            if (turn % 2 == 1)  Collections.reverse(tmp);
            list.add(tmp);
            turn++;
        }
        return list;
    }
}