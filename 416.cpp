class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
//        printf("%d\n", sum);
        if (sum % 2 == 1)   return false;
        sum = sum / 2;
        int n = nums.size();
        // unordered_set<int> possible[n + 2];
        // possible[0].insert(0);
        bool dp[n + 2][sum + 5];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = true;
            for (int j = sum; j >= nums[i - 1]; --j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        bool isFind = false;
        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j <= sum; ++j) {
        //         printf("%d ", dp[i][j]);
        //     }
        //     puts("");
        // }
        for (int i = 1; i <= n; ++i) {
            isFind = isFind || dp[i][sum];
        }
        return isFind;
    }
};