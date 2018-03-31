/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (29.44%)
 * Total Accepted:    100.3K
 * Total Submissions: 340.8K
 * Testcase Example:  '1\n1'
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
public:
    string getPermutation(int n, int k) {
		vector<int> permutation(n + 1, 1);
		for (int i = 1; i <= n; ++i) {
			permutation[i] = permutation[i - 1] * i;
		}
		vector<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
		int num = n - 1;
		string ans;
		while (num > 0) {
			int tmp = (k - 1) / (permutation[num--]);
			k = k - tmp * permutation[num + 1];
			ans += digits[tmp];
			digits.erase(digits.begin() + tmp);
		}
		ans += digits[0];
		return ans;
    }
};
