/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (27.79%)
 * Total Accepted:    126.8K
 * Total Submissions: 455.6K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
	string multiply(string num1, string num2) {
		int tmp[(num1.size() + num2.size()) * 2];
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		memset(tmp, 0, sizeof tmp);
		for (int i = 0; i < num1.size(); ++i) {
			for (int j = 0; j < num2.size(); ++j) {
				tmp[i + j] += ((num1[i] - '0') * (num2[j] - '0'));
				tmp[i + j + 1] += tmp[i + j] / 10;
				tmp[i + j] %= 10;
			}
		}
		int f = (num1.size() + num2.size()) * 2 - 1;
		while (tmp[f] == 0 && f > 0)	f--;
		if (f < 0)	return "0";
		string ans = "";
		for (int i = f; i >= 0; --i) {
			ans += (tmp[i] + '0');
		}
		return ans;
	}
};
