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
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr){
            return true;
        }

        return isSymmetricTre(root->left,root->right);
    }

    bool isSymmetricTre(TreeNode* root1, TreeNode* root2){

        if(root2==nullptr && root1==nullptr)
            return true;

        if(root1 == nullptr || root2 == nullptr || root1->val != root2->val)
            return false;

        

        return isSymmetricTre(root1->left, root2->right) && isSymmetricTre(root1->right, root2->left);

    }
};