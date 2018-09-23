class Solution {
    public double myPow(double x, long n) {
        if (n < 0)  x = 1.0 / x;
        double ans = getAnswer(x, Math.abs(n));
        return ans;
    }
    public double getAnswer(double x, long n) {
        double ans = 1.0;
        while (n > 0) {
            if (n % 2 == 1)  ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
}