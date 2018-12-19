/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode father = new ListNode(-1);
        if (m == n) return head;
        father.next = head;
        ListNode a, b;
        a = b = father;
        ListNode pre = null;
        int cnt = 0;
        while (cnt != m) {
            pre = a;
            a = a.next;
            cnt++;
        }
        cnt = 0;
        while (cnt != n) {
            b = b.next;
            cnt++;
        }
        b = b.next;
        for (int i = 0; i < n - m + 1; ++i) {
            ListNode tmp = a.next;
            a.next = b;
            b = a;
            a = tmp;
        }
        pre.next = b;
        return father.next;
    }
}