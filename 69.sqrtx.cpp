/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (28.68%)
 * Total Accepted:    211.4K
 * Total Submissions: 736.4K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 * 
 * x is guaranteed to be a non-negative integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we want to return
 * an integer, the decimal part will be truncated.
 * 
 * 
 */
class Solution {
public:
	int mySqrt(int x) {
		long long l = 0, r = x;
		long long mid, ans;
		while (l <= r) {
			mid = (l + r) >> 1LL;
			if (mid * mid > x) {
				r = mid - 1;
			} else {
				ans = mid;
				l = mid + 1;
			}
		}
		return ans;
	}
};
