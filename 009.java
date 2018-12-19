/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (35.64%)
 * Total Accepted:    282.2K
 * Total Submissions: 791.9K
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
class Solution {
    public boolean isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		int dt [] = new int[30];
		int cnt = 0;
		while (x > 0) {
			dt[cnt++] = x % 10;
			x /= 10;
		}
		int l = 0, r = cnt - 1;
		boolean f = true;
		while (l < r) {
			if (dt[l] != dt[r])	f = false;
			l++;
			r--;
		}
		return f;
    }
}
