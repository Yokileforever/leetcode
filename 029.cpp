/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.86%)
 * Total Accepted:    120.4K
 * Total Submissions: 759.5K
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
class Solution {
public:
	int num[1005];
	int two[1005];
    int divide(int dividend, int divisor) {
		int flag = 1;
		if (dividend < 0)	flag = -flag;
		if (divisor < 0)	flag = -flag;
		dividend = abs(dividend);
		divisor = abs(divisor);
		int base = divisor;
		int base2 = 1;
		int cnt = 0;
		while (base < dividend) {
			num[cnt] = base;
			two[cnt++] = base2;
			base = base + base;
			base2 = base2 + base2;
		}
		int ans = 0;
		while (--cnt >= 0) {
			if (dividend >= num[cnt]) {
				dividend -= num[cnt];
				ans += two[cnt];
			}
		}
		if (dividend > 0)	return MAX_INT;
		else	return ans * flag;
    }
};
