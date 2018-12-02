class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int n = prices.length;
        int a = -prices[0];
        int b = 0;
        for (int i = 1; i < n; ++i) {
            int newA = Math.max(a, b - prices[i]);
            int newB = Math.max(a + prices[i], b);
            a = newA;
            b = newB;
        }
        return Math.max(a, b);
    }
}