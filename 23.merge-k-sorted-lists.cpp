/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (27.89%)
 * Total Accepted:    193.3K
 * Total Submissions: 692.7K
 * Testcase Example:  '[]'
 *
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
	struct cmp {
		bool operator () (const ListNode *a, const ListNode *b) {
			return a->val > b->val;
		}
	};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode *, vector<ListNode *>, cmp>Q;
		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i] != NULL) {
				Q.push(lists[i]);
			}
		}
		ListNode *root, *tmp, *p;
		root = tmp = p = NULL;
		while (!Q.empty()) {
			tmp = Q.top();
			Q.pop();
			if (root == NULL) {
				root = tmp;
				p = root;
			} else {
				p->next = tmp;
				p = p->next;
			}
			if (tmp->next != NULL) {
				Q.push(tmp->next);
			}
		}
		return root;
    }
};
