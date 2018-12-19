/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (37.38%)
 * Total Accepted:    146.4K
 * Total Submissions: 391.2K
 * Testcase Example:  '[]'
 *
 * 
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after
 * raining. 
 * 
 * 
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * 
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 */
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int *suf = new int[n];
		int *pre = new int[n];
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1)	suf[i] = height[i];
			else	suf[i] = max(suf[i + 1], height[i]);
		}
		for (int i = 0; i < n; ++i) {
			if (i == 0)	pre[i] = height[i];
			else	pre[i] = max(pre[i - 1], height[i]);
		}
		int ans = 0;
		for (int i = 1; i < n - 1; ++i) {
			int tmp = min(pre[i - 1], suf[i + 1]);
			if (tmp > height[i])	ans += tmp - height[i];
		}
		return ans;
	}
};
