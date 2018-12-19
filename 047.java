class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        dfs(nums, 0, ans);
        return ans;
    }
    public void dfs(int[] nums, int start, List<List<Integer>> ans) {
        if (start == nums.length) {
            ArrayList<Integer> list = new ArrayList<Integer>();
            for (int i = 0; i < nums.length; ++i) {
                list.add(nums[i]);
            }
            ans.add(list);
            return ;
        }
        for (int i = start; i < nums.length; ++i) {
            if (!check(nums, start, i)) continue;
            swap(nums, i, start);
            dfs(nums, start + 1, ans);
            swap(nums, i, start);
        }
    }
    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    public boolean check(int[] nums, int l, int r) {
        for (int i = l; i < r; ++i) {
            if (nums[i] == nums[r]) return false;
        }
        return true;
    }
}