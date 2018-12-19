/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (38.81%)
 * Total Accepted:    194.5K
 * Total Submissions: 501.1K
 * Testcase Example:  '[]'
 *
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * 
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 * 
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
		if (head == NULL)	return head;
		if (head->next == NULL)	return head;
		ListNode *rt = head;
		ListNode *pre = head, *suf = head->next;
		while (true) {
			swap(pre->val, suf->val);
			if (suf->next == NULL)	break;
			suf = suf->next;
			if (suf->next == NULL)	break;
			suf = suf->next;
			pre = pre->next->next;
		}
		return rt;
    }
};
