/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (28.92%)
 * Total Accepted:    135.2K
 * Total Submissions: 467.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
	const int qq = 1e5 + 10;
    void nextPermutation(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
    }
};
