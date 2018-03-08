/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.04%)
 * Total Accepted:    177.8K
 * Total Submissions: 555K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
	int lengthOfLastWord(string s) {
		int cnt = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (isalpha(s[i])) {
				cnt = 0;
				while (isalpha(s[i]) && i < s.size()) {
					cnt++;
					i++;
				}
			}	
		}
		return cnt;
	}
};
