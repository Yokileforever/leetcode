class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        int dp[n + 5][m + 5];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n + 1; ++i) {
            dp[i][0] = dp[i][m + 1] = 1e9;
        }
        for (int i = 0; i <= m + 1; ++i) {
            dp[0][i] = dp[n + 1][i] = 1e9;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1)   dp[i][j] = grid[i - 1][j - 1];
                else    dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};