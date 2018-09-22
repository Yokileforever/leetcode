class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] <= n) {
                nums[k++] = nums[i];
            }
        }
        for (int i = 0; i < k; ++i) {
            int num = nums[i];
            if (num < 0)    num *= -1;
            if (nums[num - 1] > 0)
                nums[num - 1] *= -1;
        }
        for (int i = 0; i < k; ++i) {
            if (nums[i] > 0)    return i + 1;
        }
        return k + 1;
    }
}