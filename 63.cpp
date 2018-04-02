class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;
        int dp[n + 5][m + 5];
        memset(dp, 0, sizeof(dp));
        if (obstacleGrid[0][0] == 1)    return 0;
        dp[1][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (obstacleGrid[i - 1][j - 1] == 1)    continue;
                dp[i][j] += dp[(i - 1)][j] + dp[i][(j - 1)];
            }
        }
        return dp[n][m];
    }
};