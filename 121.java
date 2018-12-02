class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        int profit = 0, minx = prices[0];
        for (int i = 1; i < prices.length; ++i) {
            if (prices[i] > minx) {
                profit = Math.max(profit, prices[i] - minx);
            }
            minx = Math.min(minx, prices[i]);
        }
        return profit;
    }
}