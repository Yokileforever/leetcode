/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null)   return null;
        int tot = 0;
        ListNode rt = head;
        while (rt != null) {
            tot++;
            rt = rt.next;
        }
        TreeNode ans = dfs(head, 0, tot - 1);
        return ans;
    }
    public TreeNode dfs(ListNode head, int l, int r) {
        if (l > r)  return null;
        int mid = (l + r) >> 1;
        int cnt = mid - l + 1;
        ListNode tail = head;
        while ((--cnt) > 0) {
            tail = tail.next;
        }
        TreeNode rt = new TreeNode(tail.val);
        if (l == r) return rt;
        rt.left = dfs(head, l, mid - 1);
        rt.right = dfs(tail.next, mid + 1, r);
        return rt;
    }
}