class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for (int i = 0; i < (1 << (int)nums.size()); ++i) {
            tmp.clear();
            for (int j = 0; j < (int)nums.size(); ++j) {
                if (i & (1 << j)) {
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};