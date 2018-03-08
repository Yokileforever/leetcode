/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (29.58%)
 * Total Accepted:    152.2K
 * Total Submissions: 514.4K
 * Testcase Example:  '[2,3,1,1,4]'
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
 * Determine if you are able to reach the last index.
 * 
 * 
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * 
 * A = [3,2,1,0,4], return false.
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
 //   	int *dp = new int[nums.size() + 10];
    	int maxn = 0;
    	for (int i = 0; i < nums.size(); ++i) {
    		//if (i + nums[i] > maxn)'
    		if (nums[i] == 0)	continue;
    		if (i > maxn)	continue;
    		maxn = max(maxn, i + nums[i]);
    	}
    	if (maxn >= nums.size() - 1) {
    		return true;
    	}
    	return false;
    }
};
