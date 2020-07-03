#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <utility>
#include <algorithm>
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
    typedef pair<int, int> pii;
    int rob(TreeNode* root) {
        // 可行窃地区是二叉树
        if(root==nullptr)
            return 0;


        pii ans = helper(root);
        return max(ans.first, ans.second);

    }
    //偷r结点：左右儿子不能偷。最大价值等于不偷左儿子的最大价值+不偷右儿子的最大价值+r的价值

    //不偷r节点： 最大价值等于**偷或不偷**左儿子的最大价值+**偷或不偷**右儿子的最大价值。
    pii helper(TreeNode* root){
        if(root==nullptr)
            return {0,0};

        pii l = helper(root->left);
        pii r = helper(root->right);

        //偷
        int r0 = l.second+r.second+root->val;
        //不偷当前
        int r1 = max(l.first,l.second)+max(r.first,r.second);
        return make_pair(r0,r1);
    }
};