/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (27.29%)
 * Total Accepted:    141.6K
 * Total Submissions: 518.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * 
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 */
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
		Arrays.sort(nums);
		List<List<Integer>> res = new LinkedList<>();
		for (int i = 0; i < nums.length; ) {
			for (int j = i + 1; j < nums.length; ) {
				int l = j + 1, r = nums.length - 1;
				while (l < r) {
					int tmp = nums[i] + nums[j] + nums[l] + nums[r];
					if (tmp == target) {
						res.add(Arrays.asList(nums[i], nums[j], nums[l], nums[r]));
						l++;
						r--;
						while (l < r && nums[l] == nums[l - 1])	l++;
						while (l < r && nums[r] == nums[r + 1])	r--;
					} else if (tmp < target) {
						l++;
						while (l < r && nums[l] == nums[l - 1])	l++;
					} else {
						r--;
						while (l < r && nums[r] == nums[r + 1])	r--;
					}
				}
				j++;
				while (j < nums.length && nums[j] == nums[j - 1])	j++;
			}
			i++;
			while (i < nums.length && nums[i] == nums[i - 1])	i++;
		}
		return res;
    }
}
