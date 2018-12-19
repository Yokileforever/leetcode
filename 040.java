/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (35.21%)
 * Total Accepted:    139.4K
 * Total Submissions: 395.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
	public List<List<Integer>> combinationSum2(int[] candidates, int target) {
		List<List<Integer>> li = new ArrayList<List<Integer>>();
		Arrays.sort(candidates);
		dfs(li, new ArrayList<Integer>(), candidates, target, 0);
		return li;
	}
	public void dfs(List<List<Integer>> combinations, List<Integer> ans, int[] candidates, int target, int start) {
		if (target == 0) {
			combinations.add(new ArrayList<Integer>(ans));
			return ;
		} else if (target > 0) {
			for (int i = start; i < candidates.length && target >= candidates[i]; ++i) {
				ans.add(candidates[i]);
				dfs(combinations, ans, candidates, target - candidates[i], i + 1);
				ans.remove(ans.size() - 1);
				while (i + 1 < candidates.length && candidates[i] == candidates[i + 1])	i++;
			}
		}
	}
}
