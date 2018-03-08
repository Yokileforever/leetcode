/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.05%)
 * Total Accepted:    215.8K
 * Total Submissions: 633.6K
 * Testcase Example:  '[1]\n1'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		int cnt = 1;
		ListNode *rt = head;
		while (rt->next != NULL) {
			cnt++;
			rt = rt->next;
		}
		n = cnt - n;
		n++;
		rt = head;
		cnt = 1;
		if (n == 1) {
			head = head->next;
		} else {
			while (n != ++cnt) {
				rt = rt->next;
			}
			rt->next = rt->next->next;
		}
		return head;
    }
};
