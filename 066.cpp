/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.69%)
 * Total Accepted:    232.2K
 * Total Submissions: 585K
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		int tmp = 0;
		digits[n - 1] += 1;
		for (int i = n - 1; i >= 1; --i) {
			digits[i - 1] += digits[i] / 10;
			digits[i] %= 10;
		}
		if (digits[0] >= 10) {
			int tmp = digits[0] / 10;
			digits[0] %= 10;
			digits.insert(digits.begin(), tmp);
		}
		return digits;
    }
};
