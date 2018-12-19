class Solution {
    public int[] searchRange(int[] nums, int target) {
		int l = 0, r = nums.length - 1;
		int ans [] = new int[2];
		if (nums.length < 1) {
			ans[0] = ans[1] = -1;
			return ans;
		}
		int mid;
		ans[0] = nums.length - 1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] >= target) {
				ans[0] = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (nums[ans[0]] != target) {
			ans[0] = ans[1] = -1;
			return ans;
		}
		l = 0; r = nums.length - 1;
		ans[1] = nums.length;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] > target) {
				ans[1] = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans[1] = ans[1] - 1;
		return ans;
    }
}
