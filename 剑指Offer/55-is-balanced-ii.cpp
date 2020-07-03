#include <stack>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <unordered_map>
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
    //想得到的算法是，每个节点可能会被遍历很多次，需要一个更快的算法，每个节点只被遍历1次
    bool isBalanced(TreeNode* root) {
        //后序遍历
        int depth=0;
        return isBalanced(root,depth);

    }

    bool isBalanced(TreeNode* root, int &depth){

        if(root==nullptr){
            depth=0;
            return true; //空节点是平衡的
        }

        int left, right;
        if(isBalanced(root->left,left)&&isBalanced(root->right,right) && abs(left-right)<=1){
            depth = max(left,right)+1;
            return true;
        }
        return false;
    }
};
