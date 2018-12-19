/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.16%)
 * Total Accepted:    114.4K
 * Total Submissions: 494K
 * Testcase Example:  '""'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 * 
 * 
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
		int n = s.size();
		stack<int> st;
		st.push(-1);
		int maxn = 0;
		for (int i = 0; i < n; ++i) {
			int x = st.top();
			if (x != -1 && s[i] == ')' && s[x] == '(') {
				st.pop();
				maxn = max(maxn, i - st.top());
			} else {
				st.push(i);
			}
		}
		return maxn;
    }
};
