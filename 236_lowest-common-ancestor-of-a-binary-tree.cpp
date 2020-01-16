#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <climits>
using namespace std;


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
        
        TreeNode* ancestor = NULL;
        dfs(root, p, q, ancestor); //这样就可一改变它的值了

        return ancestor;
    }

    // 深度遍历，返回bool标记
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ancestor){
        bool right = false, left = false;

        if (root==NULL){
            return false;
        }

        left = dfs(root->left, p , q, ancestor); //在左边有找到 p 或 q
        right = dfs(root->right, p , q, ancestor); //在右边有找到 p 或 q
        
        if((left && right) || ((left || right) && (root==p || root==q)))
           ancestor = root;

        if(root == p || root == q || left || right)
            return true;
        else
            return false;
    }
};