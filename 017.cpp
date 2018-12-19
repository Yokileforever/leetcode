/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.05%)
 * Total Accepted:    215.8K
 * Total Submissions: 597.8K
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty())	return vector<string>();
		static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		result.push_back("");
		for (int i = 0; i < digits.size(); ++i) {
			int num = digits[i] - '0';
			if (num < 0 || num > 9)	break;
			const string &candidate = v[num];
			if (candidate.empty())	continue;
			vector<string> tmp;
			for (int j = 0; j < candidate.size(); ++j) {
				for (int k = 0; k < result.size(); ++k) {
					tmp.push_back(result[k] + candidate[j]);
				}
			}
			result.swap(tmp);
		}
		return result;
	}
};
