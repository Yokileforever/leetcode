class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int a = 0;
        int b = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            a = max(a, b + prices[i] - fee);
            b = max(b, a - prices[i]);
        }
        return max(a, b);
    }
};