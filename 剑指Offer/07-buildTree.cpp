/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
通过前序遍历和中序遍历来做
只有前序遍历 和 后序遍历做不了这个
遍历结果不包含重复数字
*/
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //前序遍历 preorder = [3,9,20,15,7]
        //中序遍历 inorder = [9,3,15,20,7]
        int len = preorder.size();
        if(len<=0)
            return nullptr;
        unordered_map<int,int> kv;
        for(int i=0;i<inorder.size();i++)
        {
            kv[inorder[i]]=i;
        }

        TreeNode* node = build(preorder,0,len-1,inorder,0,len-1,kv);

        return node;
    }

    TreeNode* build(vector<int>&preorder,int preorder_start, int preorder_end, vector<int>& inorder, int inorder_start, int inorder_end, unordered_map<int,int>& kv){

        if(preorder_end<preorder_start)
            return nullptr;

        int root = preorder[preorder_start];
        int root_inorderIndex = kv[root];
         int leftNodes = root_inorderIndex - inorder_start, rightNodes = inorder_end - root_inorderIndex;
        TreeNode* node = new TreeNode(root);

        if (preorder_start == preorder_end) {
            return node;
        }
        node->left = build(preorder, preorder_start+1, preorder_start+leftNodes, inorder, inorder_start,root_inorderIndex-1,kv);
        node->right = build(preorder,preorder_end-rightNodes+1,preorder_end, inorder, root_inorderIndex+1, inorder_end,kv);
        return node;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //前序遍历 preorder = [3,9,20,15,7]
        //中序遍历 inorder = [9,3,15,20,7]
        
        unordered_map<int,int> kv;
        int len = preorder.size();
        for(int i=0; i<len; i++)
        {
            kv[inorder[i]]=i;
        }

        TreeNode* root = build(preorder, 0, len-1, inorder, 0,len-1,kv);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int preorder_start, int preorder_end, vector<int>& inorder, int inorder_start, int inorder_end,unordered_map<int,int>&kv){
        if(preorder_start>preorder_end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preorder_start]);
        int root_index = kv[preorder[preorder_start]];

        if(preorder_start==preorder_end){
            return root;
        }

        int left_count = root_index - inorder_start;
        int right_count = inorder_end-root_index;

        root->left = build(preorder, preorder_start+1, preorder_start+left_count, inorder, inorder_start, root_index-1,kv)
        root->right = build(preorder, preorder_start+left_count+1, preorder_end, inorder, root_index+1, inorder_end,kv)

        return root;
    }  
};