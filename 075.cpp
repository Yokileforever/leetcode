/*
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (38.77%)
 * Total Accepted:    208.3K
 * Total Submissions: 537K
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue.
 * 
 * 
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * 
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * 
 * 
 * click to show follow up.
 * 
 * 
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with an one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int cnt1, cnt2, cnt3;
		cnt1 = cnt2 = cnt3 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0)	cnt1++;
			else if (nums[i] == 1)	cnt2++;
			else	cnt3++;
		}
		int l = 0;
		for (int i = 0; i < 3; ++i) {
			handle(i, nums, l);
		}
	}
	void handle(int x, vector<int>& nums, int &l) {
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == x) {
				swap(nums[i], nums[l++]);
			}
		}
	}
};
