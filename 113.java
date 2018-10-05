/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> list = new ArrayList<Integer>();
        dfs(root, 0, sum, ans, list);
        return ans;
    }
    public void dfs(TreeNode rt, int now, int target, List<List<Integer>> ans, List<Integer> list) {
        if (rt == null) return ;
        now += rt.val;
        list.add(rt.val);
        if (rt.left == null && rt.right == null) {
            if (now == target) {
                ans.add(new ArrayList(list));
            }
        }
        dfs(rt.left, now, target, ans, list);
        dfs(rt.right, now, target, ans, list);
//        System.out.println(list);
        list.remove(list.size() - 1);
        return; 
    }
}