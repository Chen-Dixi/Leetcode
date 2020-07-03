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
public:
    int cur;
    int kthLargest(TreeNode* root, int k) {
        //树根，和k
        cur=0;
        int ans=-1;
        search(root,k,ans);
        return ans;
    }

    bool search(TreeNode* root, int k,int &ans){
        if(root==nullptr)
            return false;
        
        if(search(root->right, k,ans)){
            return true;
        }
        cur++;
        if(cur==k){
            ans= root->val;
            return true;
        }
        return search(root->left,k,ans);
    }
};