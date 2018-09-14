class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 5][n + 5][2];
        for (int i = 1; i <= n; ++i) {
            dp[i][i][0] = dp[i][i][1] = nums[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j + i <= n; ++j) {
                int k = j + i;
                dp[j][k][0] = nums[j - 1] - max(dp[j + 1][k][0], dp[j + 1][k][1]);
                dp[j][k][1] = nums[k - 1] - max(dp[j][k - 1][0], dp[j][k - 1][1]);
            }
        }
 //       printf("%d %d\n", dp[1][n][0], dp[1][n][1]);
        return dp[1][n][0] >= 0 || dp[1][n][1] >= 0;
    }
};