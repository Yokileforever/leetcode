/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.80%)
 * Total Accepted:    278.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() <= 2)	return {};
		vector<vector<int>> ls;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ) {
			int l = i + 1, r = nums.size() - 1;
			while (l < r) {
				if (nums[i] + nums[l] + nums[r] == 0) {
					ls.push_back({nums[i], nums[l], nums[r]});
					l++, r--;
					while (l < r && nums[l] == nums[l - 1])	l++;
					while (l < r && nums[r] == nums[r + 1])	r--;
				} else if (nums[i] + nums[l] + nums[r] < 0) {
					l++;
					while (l < r && nums[l] == nums[l - 1])	l++;
				} else {
					r--;
					while (l < r && nums[r] == nums[r + 1])	r--;
				}
			}
			i++;
			while (i < nums.size() && nums[i] == nums[i - 1])	i++;
		}
		return ls;
	}
};
