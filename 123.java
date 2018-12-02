class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n <= 1) return 0;
        int[] minx = new int[n];
        int[] maxn = new int[n];
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                minx[i] = prices[i];
            } else {
                prefix[i] = Math.max(prices[i] - minx[i - 1], prefix[i - 1]);
                minx[i] = Math.min(prices[i], minx[i - 1]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                maxn[i] = prices[i];
            } else {
                suffix[i] = Math.max(-prices[i] + maxn[i + 1], suffix[i + 1]);
                maxn[i] = Math.max(prices[i], maxn[i + 1]);
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
//            System.out.println(prefix[i - 1] + "   " + suffix[i]);
            ans = Math.max(ans, prefix[i - 1] + suffix[i]);
        }
        ans = Math.max(ans, prefix[n - 1]);
        return ans;
    }
}