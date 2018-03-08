/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.62%)
 * Total Accepted:    246.3K
 * Total Submissions: 779.1K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int minx = 1e9 + 10;
		int sz = strs.size();
		if (sz == 0)	return "";
		if (sz == 1)	return strs[0];
		int st[1005][300];
		memset(st, 0, sizeof st);
		int maxn = 0;
		for (int i = 0; i < sz; ++i) {
			maxn = max(maxn, (int)strs[i].size());
			for (int j = 0; j < strs[i].size(); ++j) {
				st[j][(int)strs[i][j]]++;
			}
		}
		string ans = "";
		for (int i = 0; i < maxn; ++i) {
			bool f = false;
			for (int j = 0; j < 300; ++j) {
				if ((int)st[i][j] == sz) {
					f = true;
					ans += (char)j;
					break;
				}
			}
			if (!f)	break;
		}
		return ans;
	}
};
