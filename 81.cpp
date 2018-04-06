class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())   return false;
        if (nums[0] == target) return true;
        while (!nums.empty() && nums[0] == nums[nums.size() - 1]) {
            nums.pop_back();
        }
        if (nums.empty())    return false;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (target == nums[mid])    return true;
            if (nums[mid] > nums[r]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < nums[l]) {
                if (target <= nums[r] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};