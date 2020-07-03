/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool helper(TreeNode* root, TreeNode* lower, TreeNode* upper)
    {
        if(root==nullptr)
            return true;
        
        int val = root->val;
        if(lower!=nullptr && lower->val>=val)  return false;
        if(upper!=nullptr && upper->val<=val) return false;

        bool left = helper(root->left, lower, root);
        bool right = helper(root->right, root, upper);

        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,nullptr,nullptr);
    }
};