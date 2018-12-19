/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.17%)
 * Total Accepted:    108.4K
 * Total Submissions: 414.3K
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * 
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 * 
 * 
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */
class Solution {
public:
	int jump(vector<int>& nums) {
		int *dp = new int[nums.size() + 10];
		memset(dp, -1, sizeof(int) * (nums.size() + 10));
		int n = nums.size();
		int mxid = 1;
		dp[1] = 0;
		for (int i = 1; i <= n; ++i) {
			int tmp = nums[i - 1] + i;
			if (tmp <= mxid)	continue;
			for (int j = mxid + 1; j <= tmp; ++j) {
				dp[j] = dp[i] + 1;
			}
			mxid = tmp;
		}
		int ans = dp[n];
		free(dp);
		return ans;
    }
};
