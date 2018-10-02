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
    int preTot;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0)    return null;
        preTot = inorder.length;
        TreeNode root = dfs(inorder, postorder, 0, inorder.length - 1);
        return root;
    }
    public TreeNode dfs(int[] inorder, int[] postorder, int l, int r) {
        if (l > r)  return null;
//        if (preTot <= 0)    return null;
        TreeNode rt = new TreeNode(postorder[--preTot]);
//        System.out.println(rt.val);
        if (l == r) return rt;
        int mid = -1;
        for (int i = l; i <= r; ++i) {
            if (postorder[preTot] == inorder[i]) {
                mid = i;
                break;
            }
        }
        rt.right = dfs(inorder, postorder, mid + 1, r);
        rt.left = dfs(inorder, postorder, l, mid - 1);
        return rt;
    }
}