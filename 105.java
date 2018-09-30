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
    int preCnt = 0;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        TreeNode root;
        root = dfs(preorder, inorder, 0, inorder.length);
        return root;
    }
    public TreeNode dfs(int[] preorder, int[] inorder, int st, int ed) {
        if (st > ed)    return null;
        if (preCnt >= inorder.length)   return null;
        int mid = 0;
        for (int i = 0; i < inorder.length; ++i) {
            if (inorder[i] == preorder[preCnt]) {
                mid = i;
                break;
            }
        }
        TreeNode root = new TreeNode(inorder[mid]);
        preCnt++;
        root.left = dfs(preorder, inorder, st, mid - 1);
        root.right = dfs(preorder, inorder, mid + 1, ed);
        return root;
    }
}