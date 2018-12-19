/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (33.75%)
 * Total Accepted:    281.8K
 * Total Submissions: 834.2K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
    public boolean isValid(String s) {
		boolean f = false;
		return isOK(s);
    }
	public boolean isOK(String s) {
		char p [] = new char[s.length() * 3];
		int cnt = 0 ;
		for (int i = 0; i < s.length(); ++i) {
			if (cnt == 0) {
				p[++cnt] = s.charAt(i);
			} else {
				char f = s.charAt(i);
				if (f == '(' || f == '{' || f == '[') {
					p[++cnt] = f;
				} else {
					if (cnt < 1)	return false;
					if (f == ')' && p[cnt] == '(')	--cnt;
					else if (f == '}' && p[cnt] == '{')	--cnt;
					else if (f == ']' && p[cnt] == '[')	--cnt;
					else return false;
				}
			}
		}
		if (cnt == 0)	return true;
		return false;
	}
}
