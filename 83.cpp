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
        if (head == NULL)   return head;
        ListNode *tmp = head;
        ListNode *ans = head;
        while (head != NULL) {
            int x = head->val;
            while (head != NULL && x == head->val) {
                head = head->next;
            }
            tmp->next = head;
            tmp = tmp->next;
        }
        return ans;
    }
};