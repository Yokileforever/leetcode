class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        bool f = false;
        sort(nums.begin(), nums.end());
        do {
            f |= dfs(nums, nums[0], 1);
            f |= twoToTwo(nums);
         //   printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
        } while(next_permutation(nums.begin(), nums.end()));
        // vector<double> ansCombination[10];
        // int n = nums.size();
        // int top = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         makeCombination(ansCombination[top], nums[i], nums[j]);
        //         top++;
        //     }
        // }
        // bool f = false;
        // f |= solve(ansCombination[0], ansCombination[5]);
        // f |= solve(ansCombination[1], ansCombination[4]);
        // f |= solve(ansCombination[2], ansCombination[3]);
        return f;
        
    }
    bool judge(double x) {
        return fabs(x - 24) < 0.0001;
    }
    bool twoToTwo(vector<int> &nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        bool f = false;
        f |= judge((a + b) * (c + d)) || judge((a + b) * (c - d)) || judge((a - b) * (c + d)) || judge((a - b) * (c - d));
        if (c + d != 0) {
            f |= judge((a + b) / (c + d)) || judge((a + b) / (c + d));
        }
        if (c - d != 0) {
            f |= judge((a + b) / (c - d)) || judge((a + b) / (c - d));
        }
        return f;
    }
    bool dfs(vector<int>& nums, double k, int cnt) {
        if (cnt == 4) {
            if (fabs(k - 24) < 0.1)   return true;
            return false;
        }
        bool f = false;
        f |= dfs(nums, k + nums[cnt], cnt + 1);
        f |= dfs(nums, nums[cnt] - k, cnt + 1);
        f |= dfs(nums, k - nums[cnt], cnt + 1);
        f |= dfs(nums, k * nums[cnt], cnt + 1);
        if (nums[cnt] != 0) {
            f |= dfs(nums, k / nums[cnt], cnt + 1);
        }
        if (k != 0) {
            f |= dfs(nums, nums[cnt] / k, cnt + 1);
        }
        return f;
    }
    void makeCombination(vector<double> &ans, double x, double y) {
        ans.push_back(x + y);
        ans.push_back(x * y);
        ans.push_back(x - y);
        ans.push_back(-x + y);
        if (y != 0)
            ans.push_back(x / y);
        if (x != 0)
            ans.push_back(y / x);
    }
    bool solve(vector<double> &x, vector<double> &y) {
        int ans = 24;
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < y.size(); ++j) {
                double tmp = x[i] + y[j];
                if ((int)tmp == ans) return true;
                tmp = x[i] * y[j];
                if ((int)tmp == ans)    return true;
                tmp = x[i] - y[j];
                if ((int)tmp == ans)    return true;
                tmp = -x[i] + y[j];
                if ((int)tmp == ans)    return true;
                if (y[j] != 0) {
                    tmp = x[i] / y[j];
                    if ((int)tmp == ans)    return true;
                }
                if (x[i] != 0) {
                    tmp = y[j] / x[i];
                    if ((int)tmp == ans)    return true;
                }
            }
        }
        return false;
    }
};