class Solution {
public:
    string minWindow(string s, string t) {
        int vis[300];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < (int)t.size(); ++i) {
            vis[t[i]]++;
        }
        int tar[300];
        memset(tar, 0, sizeof(tar));
        int l, r, minx;
        minx = 1e9;
        int window = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            tar[s[i]]++;
            bool f = true;
            for (int j = 0; j < 300; ++j) {
                if (tar[j] < vis[j])  f = false;
            }
            if (!f) continue;
            while (true) {
                if (tar[s[window]] - 1 < vis[s[window]]) {
                    break;
                } else {
                    tar[s[window]]--;
                    window++;
                }
            }
            if (i - window + 1 < minx) {
                minx = i - window + 1;
                l = window, r = i;
            }
        }
        if (minx == 1e9)    return "";
        string ans = s.substr(l, r - l + 1);
        return ans;
    }
};