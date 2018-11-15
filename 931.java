class Solution {
    public int minFallingPathSum(int[][] A) {
        if (A == null)  return 0;
        int n = A.length;
        int m = A[0].length;
        int[][] dp = new int[n][m];
        System.arraycopy(A[0], 0, dp[0], 0, m);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = 1000000000;
                if (j - 1 >= 0) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + A[i][j]);
                }
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + A[i][j]);
                if (j + 1 < m) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j + 1] + A[i][j]);
                }
            }
        }
        int maxn = 1000000000;
        for (int i = 0; i < m; ++i) {
            maxn = Math.min(maxn, dp[n - 1][i]);
        }
        return maxn;
    }
}