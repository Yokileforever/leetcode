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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)   return head;
        ListNode *rt = new ListNode(-1);
        rt->next = head;
        ListNode *now = head, *pre = rt;
        ListNode *first = rt;
        while (now != NULL) {
            if (now->val < x) {
                if (first->next == now) {
                    first = first->next;
                    pre = now;
                    now = now->next;
                } else {
                    pre->next = now->next;
                    now->next = first->next;
                    first->next = now;
                    now = pre->next;
                    first = first->next;
                }
            } else {
                pre = now;
                now = now->next;
            }
        }
        return rt->next;
    }
};


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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)   return head;
        ListNode node1(-1), node2(-1);
        ListNode *a = &node1;
        ListNode *b = &node2;
        while (head) {
            if (head->val < x) {
                a = a->next = head;
            } else {
                b = b->next = head;
            }
            head = head->next;
        }
        b->next = NULL;
        a->next = node2.next;
        return node1.next;
    }
};
