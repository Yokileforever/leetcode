/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (46.88%)
 * Total Accepted:    185.4K
 * Total Submissions: 395.3K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
	vector<string> ls;
    vector<string> generateParenthesis(int n) {
		dfs("", 0, 0, n);
		return ls;
    }
	void dfs(string x, int open, int close, int n) {
		if (x.size() == 2 * n) {
			ls.push_back(x);
			return ;
		}
		if (open < n) {
			dfs(x + "(", open + 1, close, n);
		} 
		if (close < open) {
			dfs(x + ")", open, close + 1, n);
		}
	}
};
