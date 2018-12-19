/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (20.75%)
 * Total Accepted:    114.5K
 * Total Submissions: 550.5K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * 
 */
class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.size(), m = p.size();
		int i = 0, j = 0;
		bool dp[2][3005] = {0};
		dp[0][0] = 1;
		while (i < m && p[i] == '*') {
			dp[0][i + 1] = 1;
			++i;
		}
		int x = 0;
		for (i = 1; i <= n; ++i) {
			x = x ^ 1;
			for (j = 1; j <= m; ++j) {
				if (p[j - 1] == '*') {
					dp[x][j] = dp[x ^ 1][j] || dp[x][j - 1];
				} else {
					dp[x][j] = dp[x ^ 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
				}
			}
			dp[x ^ 1][0] = dp[x][0];
		}
		return dp[x][m];
	}
};
