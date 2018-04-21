int numComponents(ListNode* head, vector<int>& G) {
    unordered_set<int> setG (G.begin(), G.end());
    int res = 0;
    while (head != NULL) {
        if (setG.count(head->val) && (head->next == NULL || !setG.count(head->next->val))) res++;
        head = head->next;
    }
    return res;
}

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
    int numComponents(ListNode* head, vector<int>& G) {
        int cnt = 0;
        ListNode *tmp = head;
        while (tmp != NULL) {
            cnt++;
            tmp = tmp->next;
        }
        if (cnt == 0)   return 0;
        sort(G.begin(), G.end());
        bool isvis[cnt + 10];
        memset(isvis, false, sizeof(isvis));
        tmp = head;
        cnt = 0;
        while (tmp != NULL) {
            ++cnt;
            if (check(tmp->val, G)) {
                isvis[cnt] = true;
            }
            tmp = tmp->next;
        }
        int ans = 0;
        int ct = 0;
        for (int i = 1; i <= cnt; ++i) {
            if (isvis[i] == true) {
                ct++;
            } else {
                if (ct > 0) {
                    ans++;
                    ct = 0;
                }
            }
        }
        if (ct > 0)    ans++;
        return ans;
    }
    bool check(int val, vector<int> &G) {
        int l = 0, r = G.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (G[mid] == val)  return true;
            else if (G[mid] < val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
 };