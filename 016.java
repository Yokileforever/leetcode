/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (31.46%)
 * Total Accepted:    156.8K
 * Total Submissions: 498.5K
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
	public int threeSumClosest(int[] nums, int target) {
		Arrays.sort(nums);
		int minx = Integer.MAX_VALUE;
		int ans = -1;
		for (int i = 0; i < nums.length; ++i) {
			for (int j = i + 1; j < nums.length; ++j) {
				int tmp = -nums[i] - nums[j] + target;
				int k = find(nums, j + 1, nums.length - 1, tmp);
				if (k == -1)	continue;
				int cpar = nums[i] + nums[j] + nums[k];
				if (Math.abs((nums[i] + nums[j] + nums[k]) - target) < minx) {
					minx = Math.abs(cpar - target);
					ans = cpar;
				}
				if (k - 1 > j) {
					cpar = nums[i] + nums[j] + nums[k - 1];
					if (Math.abs((nums[i] + nums[j] + nums[k - 1]) - target) < minx) {
						minx = Math.abs(cpar - target);
						ans = cpar;
					}
				}
			}
		}
		return ans;
	}
	public int find(int nums [], int l, int r, int x) {
		if (l > r)	return -1;
		int id = r;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (nums[mid] < x) {
				l = mid + 1;
			} else {
				id = mid;
				r = mid - 1;
			}
		}
		return id;
	}
}
