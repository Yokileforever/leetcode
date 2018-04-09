class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        bool dp[n +  5][n + 5][n + 5];
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = (s1[i] == s2[j] ? true : false);
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                for (int j = 0; j < n - len + 1; ++j) {
                    for (int k = 1; k < len; ++k) {
                        dp[i][j][len] |= (dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i][j + (len - k)][k] && dp[i + k][j][len - k]);
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};