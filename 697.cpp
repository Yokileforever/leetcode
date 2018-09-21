class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxn = -1;
        for (int i = 0; i < nums.size(); ++i) {
            maxn = max(maxn, nums[i]);
        }
        vector<int> index[maxn + 5];
        for (int i = 0; i < nums.size(); ++i) {
            index[nums[i]].push_back(i);
        }
        int minx = 1e9;
        int n = maxn;
        maxn = 0;
        for (int i = 0; i <= n; ++i) {
            if (index[i].size() == 0)   continue;
            if (index[i].size() > maxn) {
                maxn = index[i].size();
                minx = index[i][index[i].size() - 1] - index[i][0] + 1;
            } else if (index[i].size() == maxn) {
                minx = min(minx, index[i][index[i].size() - 1] - index[i][0] + 1);
            }
        }
        return minx;
    }
};