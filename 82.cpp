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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *hc = new ListNode(-1);
        ListNode *now = hc;
        while (head != NULL) {
            int cnt = 1;
            while (head->next != NULL && head->val == head->next->val) {
                ++cnt;
                head = head->next;
            }
            if (cnt == 1) {
                now->next = head;
                now = now->next;
            }
            head = head->next;
        }
        now->next = NULL;
        return hc->next;
    }
};