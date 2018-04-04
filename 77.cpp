class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        bool vis[n + 5];
        memset(vis, false, sizeof(vis));
        dfs(n, k, 0, ans, tmp, vis, 1);
        return ans;
    }
    void dfs (int n, int k, int cnt, vector<vector<int>>& ans, vector<int> &tmp, bool *vis, int x) {
        if (cnt == k) {
            ans.push_back(tmp);
            return ;
        }
        for (int i = x; i <= n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                tmp.push_back(i);
                dfs(n, k, cnt + 1, ans, tmp, vis, i + 1);
                vis[i] = false;
                tmp.pop_back();
            }
        }
    }
};

void combine (int n, int m, vector<int> b) {
    for (int i = n; i >= m; --i) {
        b[m - 1] = i;
        if (m > 1) {
            combine(i - 1, m - 1, b);
        } else {
            for (int i = b.size() - 1; i >= 0; --i) {
                cout << b[i] << " ";
            }
            cout << endl;
        }
    }
}