/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null)   return;
        Queue<TreeLinkNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int n = queue.size();
            List<TreeLinkNode> list = new ArrayList<>();
            int cntNode = 0;
            for (int i = 0; i < n; ++i) {
                TreeLinkNode node = queue.poll();
                if (node.left != null) {
                    list.add(node.left);
                    cntNode++;
                }
                if (node.right != null) {
                    list.add(node.right);
                    cntNode++;
                }
            }
            for (int i = 0; i < cntNode - 1; ++i) {
                list.get(i).next = list.get(i + 1);
                queue.offer(list.get(i));
            }
            if (cntNode != 0)
                queue.offer(list.get(cntNode - 1));
            
        }
    }
}


/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 * O(1) space
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null)   return;
        TreeLinkNode leftStart = root;
        while (leftStart != null) {
            TreeLinkNode cur = leftStart;
            while (cur != null) {
                if (cur.right != null) {
                    cur.left.next = cur.right;
                }
                if (cur.next != null && cur.next.left != null) {
                    cur.right.next = cur.next.left;
                }
                cur = cur.next;
            }
            leftStart = leftStart.left;
        }
    }
}