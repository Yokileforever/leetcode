/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (31.17%)
 * Total Accepted:    114.6K
 * Total Submissions: 367.5K
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * 
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be
 * changed.
 * 
 * Only constant memory is allowed.
 * 
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * 
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * 
 * 
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 0 || k == 1)	return head;
		ListNode *rt = head;
		int tot = 0;
		while (rt != NULL) {
			tot++;
			rt = rt->next;
		}
		int loop = tot / k;
		if (loop < 1)	return head;
		ListNode *l, *r;
		l = r = NULL;
		l = head;
		ListNode *x, *y;
		x = y = NULL;
		ListNode *pre = NULL;
		for (int i = 0; i < loop; ++i) {
			int cnt = 0;
			if (i == 0) {
				cnt = 1;
				r = l->next;
				x = l;
				while (cnt < k) {
					y = r;
					r = r->next;
					y->next = x;
					x = y;
					cnt++;
				}
				rt = x;
				pre = l;
				l->next = r;
			} else {
				l = r;
				cnt = 1;
				r = l->next;
				x = l;
				while (cnt < k) {
					y = r;
					r = r->next;
					y->next = x;
					x = y;
					cnt++;
				}
				pre->next = x;
				l->next = r;
				pre = l;
			}
		}
		return rt;
    }
};
