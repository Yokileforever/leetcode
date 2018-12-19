/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (40.81%)
 * Total Accepted:    98.9K
 * Total Submissions: 241.7K
 * Testcase Example:  '0'
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 * 
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
 		vector<vector<int>> ls(n, vector<int>(n, 0));
		int l = 0, r = n - 1, u = 0, d = n - 1;
		int cnt = 0;
		while (l <= r && u <= d) {
			for (int i = l; i <= r; ++i) {
				ls[u][i] = ++cnt;
			}
			if (u + 1 > d)	break;
			u++;
			for (int i = u; i <= d; ++i) {
				ls[i][r] = ++cnt;
			}
			if (r - 1 < l)	break;
			r--;
			for (int i = r; i >= l; --i) {
				ls[d][i] = ++cnt;
			}
			if (d - 1 < u)	break;
			d--;
			for (int i = d; i >= u; --i) {
				ls[i][l] = ++cnt;
			}
			if (l + 1 > r)	break;
			++l;
		}
		return ls;
    }
};
