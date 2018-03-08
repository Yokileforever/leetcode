/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (39.77%)
 * Total Accepted:    295.5K
 * Total Submissions: 742.3K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode root = null, tmp = null;
		while (l1 != null && l2 != null) {
			if (l1.val > l2.val) {
				if (root == null) {
					root = new ListNode(l2.val);
					tmp = root;
				} else {
					tmp.next = new ListNode(l2.val);
					tmp = tmp.next;
				}
				l2 = l2.next;
			} else {
				if (root == null) {
					root = new ListNode(l1.val);
					tmp = root;
				} else {
					tmp.next = new ListNode(l1.val);
					tmp = tmp.next;
				}
				l1 = l1.next;
			}
		}
		while (l1 != null) {
			if (root == null) {
				root = new ListNode(l1.val);
				tmp = root;
			} else {
				tmp.next = new ListNode(l1.val);
				tmp = tmp.next;
			}
			l1 = l1.next;
		}
		while (l2 != null) {
			if (root == null) {
				root = new ListNode(l2.val);
				tmp = root;
			} else {
				tmp.next = new ListNode(l2.val);
				tmp = tmp.next;
			}
			l2 = l2.next;
		}
		return root;
    }
}
