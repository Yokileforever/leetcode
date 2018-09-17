/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// bubble sort 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)   return NULL;
        while (true) {
            int cnt = 0;
            ListNode *start = head;
            while (start->next) {
                if (start->next->val < start->val) {
                    swap(start->val, start->next->val);
                    cnt++;
                }
                start = start->next;
            }
            if (cnt == 0)   break;
        }
        return head;
    }
};

// insert sort
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)   return NULL;
        if (head->next  == NULL)    return head;
        ListNode *p = new ListNode(-1), *start = head->next;
        p->next = head;
        while (start) {
            ListNode *tmp = p->next, *ans = NULL;
            while (true) {
                if (tmp->val <= start->val) {
                    ans = tmp;
                }
                if (tmp->next == start) break;
                tmp = tmp->next;
            }
            if (ans == NULL) {
                ans = p;
            }
            if (ans != tmp) {
                tmp->next = start->next;
                start->next = ans->next;
                ans->next = start;
                start = tmp->next;
            } else {
                start = start->next;
            }
            
            //printf("%d\n", start->val);
        }
        return p->next;
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
// insert sort, just swap value.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        const int INF = 1e9 + 10;
        if (head == NULL)   return NULL;
        if (head->next  == NULL)    return head;
        ListNode *p = head->next, *rt = new ListNode(-1);
        rt->next = head;
        while (p != NULL) {
            ListNode *start = head, *id = NULL;
            while (start != p) {
                if (start->val < p->val) {
                    id = start;
                }
                start = start->next;
            }
            if (id == NULL) id = rt;
            int tmp;
            if (id->next != p) {
                id = id->next;
                ListNode *h = id;
                if (id->next == p) {
                    swap(id->val, p->val);
                } else {
                    int tmp;
                    while (id != p->next) {
                        int x = id->val;
                        id->val = tmp;
                        tmp = x;
                        id = id->next;
                    }
                    h->val = tmp;
                }
            }
            p = p->next;
        }
        return head;
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
// quick sort
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        const int INF = 1e9 + 10;
        if (head == NULL)   return NULL;
        if (head->next  == NULL)    return head;
        quickSort(head, NULL);
        return head;
    }
    void quickSort(ListNode *l, ListNode *r) {
        if (l != r) {
            ListNode* mid = realSort(l, r);
            quickSort(l, mid);
            quickSort(mid->next, r);
        }
    }
    ListNode* realSort(ListNode *l, ListNode *r) {
        int x = l->val;
        ListNode *process = l, *low = l;
        
        while (l != r) {
            if (l->val < x) {
                process = process->next;
                swap(process->val, l->val);
            }
            l = l->next;
        }
        swap(process->val, low->val);
        return process;
    }
};