class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int dp[n + 5][m + 5];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = dp[0][i - 1] + s2[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};