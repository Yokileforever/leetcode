/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (37.13%)
 * Total Accepted:    176.8K
 * Total Submissions: 474.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
	public List<List<String>> groupAnagrams(String[] strs) {
		if (strs == null || strs.length == 0) {
			return new ArrayList<List<String>>();
		}
		Map<String, List<String>> map = new HashMap<String, List<String>>();
		for (String s : strs) {
			char[] ca = s.toCharArray();
			Arrays.sort(ca);
			String key = String.valueOf(ca);
			if (!map.containsKey(key))	map.put(key, new ArrayList<String>());
			map.get(key).add(s);
		}
		return new ArrayList<List<String>>(map.values());
	}
}
