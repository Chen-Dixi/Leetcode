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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 最近公共祖先，that is to say, 1. 节点p 和 q分别在这个祖先节点的两边。 2. 祖先节点是p,q其中之一
        // 最近公共祖先
        //二叉搜索树的情况，大小第一个位于p和q之间的就是最近公共祖先
        if(root=nullptr){
            return nullptr;
        }

        if((root->val-p->val)*(root->val-q->val)<0)
            return root;
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        //如果都不是上面的，说明当前root就是p或者q
        return root;  
    }
};

class Solution {
public:
    //普通二叉树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 最近公共祖先，that is to say, 1. 节点p 和 q分别在这个祖先节点的两边。 2. 祖先节点是p,q其中之一
        // 最近公共祖先
        //二叉搜索树的情况，大小第一个位于p和q之间的就是最近公共祖先
        if(root==nullptr || root==p || root==q){
            return root;
        }

        TreeNode * left = lowestCommonAncestor(root->left, p,q);
        TreeNode * right = lowestCommonAncestor(root->right, p,q);

        if(left && right)
            return root;

        //如果都不是上面的，说明当前root就是p或者q
        return left==nullptr ? right : left;  
    }
};