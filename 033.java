/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.06%)
 * Total Accepted:    222.3K
 * Total Submissions: 693.4K
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
    public int search(int[] nums, int target) {
		if (nums.length == 0) {
			return -1;
		} else if (nums.length == 1) {
			if (nums[0] == target)	return 0;
			else	return -1;
		}
		int tmp = findMin(nums);
		if (nums[tmp] == target)	return tmp;
		int n = nums.length;
		int l = (target <= nums[n - 1]) ? tmp : 0;
		int r = (target > nums[n - 1]) ? tmp : n - 1; 
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (nums[mid] == target)	return mid;
			else if (nums[mid] < target)	l = mid + 1;
			else	r = mid - 1;
		}
		return -1;
    }
	public int findMin(int [] x) {
		int l = 0, r = x.length - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (x[mid] > x[r]) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
}
