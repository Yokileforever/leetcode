class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        int i = 0;
        for (int x : nums) {
            if (i < 2 || x > nums[i - 2]) {
                nums[i++] = x;
            }
        }
        return i;
    }
};