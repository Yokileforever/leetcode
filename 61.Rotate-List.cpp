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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)   return NULL;
        if (k == 0) return head;
        int tot = 0;
        ListNode *tmp = head;
        while (tmp != NULL) {
            tot++;
            tmp = tmp->next;
        }
        k %= tot;
        if (tot == 1) {
            return head;
        }
        int cnt = 0;
        dfs(head, head, cnt, k);
        cnt = 0;
        tmp = head;
        while (++cnt < tot) {
            tmp = tmp->next;
        }
        tmp->next = NULL;
        return head;
    }
    void dfs(ListNode *&head, ListNode *now, int &cnt, int k) {
        if (now == NULL)    return ;
        dfs(head, now->next, cnt, k);
        cnt++;
        if (cnt <= k) {
            now->next = head;
            head = now;
        } else if (cnt == k + 1) {
            now->next = NULL;
        }
        return ;
    }
};