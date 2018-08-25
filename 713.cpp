class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        long long productTmp = 1;
        int start = 0, n = nums.size();
        long long ans = 0;
        int i = 0;
        while (i < n) {
            productTmp *= nums[i++];
 //           printf("---- %d\n", productTmp);
            while (productTmp >= k && start < i) {
                ans += i - start - 1;
//                printf("%d\n", ans);
                productTmp /= nums[start++];
            }
        }
        while (start < n) {
            ans += (n - start);
//            printf("%d\n", ans);
            start++;
        }
        return (int)ans;
    }
};