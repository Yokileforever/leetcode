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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0)    return null;
        TreeNode root = dfs(nums, 0, nums.length - 1);
        return root;
    }
    public TreeNode dfs(int[] nums, int l, int r) {
        if (l > r)  return null;
        int mid = (l + r) >> 1;
        TreeNode rt = new TreeNode(nums[mid]);
        if (l == r) return rt;
        rt.left = dfs(nums, l, mid - 1);
        rt.right = dfs(nums, mid + 1, r);
        return rt;
    }
}