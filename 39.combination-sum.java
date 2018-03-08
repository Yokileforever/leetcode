/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (40.44%)
 * Total Accepted:    197.8K
 * Total Submissions: 488.4K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
	public List<List<Integer>> combinationSum(int[] candidates, int target) {
		List<List<Integer>> li = new ArrayList<List<Integer>>();
//		List<Integer> tmp = new ArrayList<Integer>();
		Arrays.sort(candidates);
		dfs(li, new ArrayList<Integer>(), candidates, target, 0);
		return li;
	}
	public void dfs(List<List<Integer>> combinations, ArrayList<Integer> ans, int [] candidates, int target, int start) {
		if (target > 0) {
			for (int i = start; i < candidates.length && target >= candidates[i]; ++i) {
				ans.add(candidates[i]);
				dfs(combinations, ans, candidates, target - candidates[i], i);
				ans.remove(ans.size() - 1);
			}
		} else if (target == 0) {
			combinations.add(new ArrayList<Integer>(ans));
			return ;
		}
	}
}
