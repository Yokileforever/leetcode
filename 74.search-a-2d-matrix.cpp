/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.78%)
 * Total Accepted:    150.2K
 * Total Submissions: 432.2K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * 
 * 
 * Given target = 3, return true.
 */
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())	return false;
		int n = matrix.size(), m = matrix[0].size();
		int l = 0, r = n * m - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (matrix[mid / m][mid % m] == target)	return true;
			else if (matrix[mid / m][mid % m] > target)	{
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return false;
	}
};
