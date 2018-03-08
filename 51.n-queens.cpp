/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (32.72%)
 * Total Accepted:    93.9K
 * Total Submissions: 287.1K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 
 */
class Solution {
public:
	void dfs(int x, int n, bool *row, bool *col, bool *diagonal, bool *undiagonal, vector<string> &st, vector<vector<string>> &ans) {
		if (x == n) {
			ans.push_back(st);
			return ;
		}
		for (int i = 0; i < n; ++i) {
			if (!row[x] && !col[i] && !diagonal[i - x + n] && !undiagonal[i + x]) {
				row[x] = col[i] = diagonal[i - x + n] = undiagonal[i + x] = true;
				st[x][i] = 'Q';
				dfs(x + 1, n, row, col, diagonal, undiagonal, st, ans);
				st[x][i] = '.';
				row[x] = col[i] = diagonal[i - x + n] = undiagonal[i + x] = false;
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<string> st(n, string(n, '.'));
		vector<vector<string>> ans;
		bool row[n + 5], col[n + 5], diagonal[2 * n + 5], undiagonal[2 * n + 5];
		memset(row, false, sizeof row);
		memset(col, false, sizeof col);
		memset(diagonal, false, sizeof diagonal);
		memset(undiagonal, false, sizeof undiagonal);
		dfs(0, n, row, col, diagonal, undiagonal, st, ans);
		return ans;
	}

};
