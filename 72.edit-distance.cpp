/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (32.41%)
 * Total Accepted:    109.7K
 * Total Submissions: 338.2K
 * Testcase Example:  '""\n""'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * 
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 
 */
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length();
		int n = word2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			dp[i][0] = i;
		}
		for (int i = 1; i <= n; ++i) {
			dp[0][i] = i;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
					dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
				}
			}
		}
		return dp[m][n];
	}
};
