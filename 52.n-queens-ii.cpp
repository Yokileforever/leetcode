/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (46.35%)
 * Total Accepted:    72K
 * Total Submissions: 155.4K
 * Testcase Example:  '1'
 *
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 * 
 * 
 */
class Solution {
public:
	
    int totalNQueens(int n) {
    	bool row[n + 10];
    	bool col[n + 10];
    	bool diagonal[n + n + 10];
    	bool undiagonal[n + n + 10];
    	memset(row, false, sizeof row);
    	memset(col, false, sizeof col);
    	memset(diagonal, false, sizeof diagonal);
    	memset(undiagonal, false, sizeof undiagonal);
    	int ans = 0;
    	dfs(1, n, row, col, diagonal, undiagonal, ans);
    	return ans;
    }
    void dfs(int x, int n, bool *row, bool *col, bool *diagonal, bool *undiagonal, int &ans) {
    	if (x == n + 1) {
    		ans++;
    		return ;
    	}
    	for (int i = 1; i <= n; ++i) {
    		if (!row[x]) {
    			if (!col[i]) {
    				if (!diagonal[i - x + n]) {
    					if (!undiagonal[i + x]) {
    						row[x] = col[i] = diagonal[i - x + n] = undiagonal[i + x] = true;
    						dfs(x + 1, n, row, col, diagonal, undiagonal, ans);
    						row[x] = col[i] = diagonal[i - x + n] = undiagonal[i + x] = false;
    					}
    				}
    			}
    		}
    	}
    }
};
