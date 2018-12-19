/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (27.11%)
 * Total Accepted:    134.5K
 * Total Submissions: 495.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * 
 * 
 * For example,
 * Given the following matrix:
 * 
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 * 
 */
class Solution {
public:

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())	return vector<int>();
		int m = matrix.size(), n = matrix[0].size();
		bool vis[m + 5][n + 5];
		memset(vis, false, sizeof vis);
		int s, e;
		s = e = 0;
		vector<int> ans;
		ans.push_back(matrix[0][0]);
		vis[0][0] = true;
		while (true) {
			int x = s, y = e;
			for ( ; e + 1 < n && !vis[s][e + 1]; ++e) {
				vis[s][e + 1] = true;
				ans.push_back(matrix[s][e + 1]);
			}
			for ( ; s + 1 < m && !vis[s + 1][e]; ++s) {
				vis[s + 1][e] = true;
				ans.push_back(matrix[s + 1][e]);
			}
			for ( ; e - 1 >= 0 && !vis[s][e - 1]; --e) {
				vis[s][e - 1] = true;
				ans.push_back(matrix[s][e - 1]);
			}
			for ( ; s - 1 >= 0 && !vis[s - 1][e]; --s) {
				vis[s - 1][e] = true;
				ans.push_back(matrix[s - 1][e]);
			}
			if (x == s && y == e)	break;
		}
		return ans;
	}
};
