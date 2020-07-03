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
    int maxPath = 1<<31;
    public int maxPathSum(TreeNode root) {
        if(root==null)
            return 0;
        dfs(root);
        return maxPath;
    }

    private int dfs(TreeNode root) {
        if(root==null)
            return 0;

        int leftmax = Math.max(0,dfs(root.left));
        int rightmax = Math.max(0,dfs(root.right));

        maxPath = Math.max(maxPath, root.val+leftmax+rightmax);
        return root.val + Math.max(leftmax, rightmax);
    }
}